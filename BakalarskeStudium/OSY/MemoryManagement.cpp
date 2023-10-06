#ifndef __PROGTEST__
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <pthread.h>
#include <semaphore.h>
#include "common.h"
using namespace std;
#endif /* __PROGTEST__ */
uint32_t freepages=0;
uint32_t freepos=0;
uint32_t totalpag=0;
uint32_t * stack;
uint32_t* pamat;
pthread_mutex_t pagMtx;



uint32_t add ()
{
    
    uint32_t page=0;
    if (freepos < totalpag)
    {
        page=stack[freepos];
        stack[freepos]=0;
        freepos++;
        freepages--;
        
        
        //printf("add ano %u\n",freepages);
    }
/*    else
    {
        printf("add nie %u\n",freepages);
    }*/
    return page;
}

void returnpage ( uint32_t  retpage)
{
    if (freepos > 0)
    {
        freepos--;
        stack[freepos]=retpage;
        freepages++;
       // printf("ret ano %u\n",freepages);
    }
/*    else
    {
        printf("ret nie %u\n",freepages);
    }*/
  
}

class prvok {
public:
    uint32_t root;
    void (* entryPoint) (CCPU*, void*);
    void * processArg;
    uint32_t mypages;

    prvok(uint32_t roota, void * pA, void (* eP) (CCPU*, void*), uint32_t pages = 0) :root(roota), entryPoint(eP), processArg(pA), mypages(pages) {}
};

void * help ( void * );

class CLike : public CCPU
{
  public:
   
    virtual uint32_t         GetMemLimit                   ( void ) const{return mypages;};
    virtual bool             SetMemLimit                   ( uint32_t          pages )
    {
        uint32_t  newpage=-1;
       if  (mypages<pages)
       {
           pthread_mutex_lock(&pagMtx);
           if ((pages-mypages)<=freepages)
           {
               
                for (uint32_t i = mypages;i<pages;i++ )
               {
                    if (lv2==0)
                    {
                        lv1++;
                        newpage=add();
                        allmypages++;
                        for (unsigned j=0;j<1024;j++)
                                ((uint32_t *) m_MemStart + newpage*1024)[j]=0;

                        ((uint32_t *) m_MemStart + ((m_PageTableRoot &ADDR_MASK)>>OFFSET_BITS)*1024)[lv1-1]=4096*newpage+7;
                    }
                    newpage=add();
                    allmypages++;
                    ((uint32_t*) m_MemStart + ((((uint32_t*) m_MemStart + ((m_PageTableRoot &ADDR_MASK)>>OFFSET_BITS)*PAGE_DIR_ENTRIES)[lv1-1] &ADDR_MASK)>>OFFSET_BITS)*PAGE_DIR_ENTRIES)[lv2]=4096*newpage+7;
                    for (unsigned j=0;j<1024;j++)
                           ((uint32_t *) m_MemStart + newpage*1024)[j]=7;

                    lv2++;
                    lv2=lv2%1024;
                }
                pthread_mutex_unlock(&pagMtx);
                mypages=pages;
                return true;
           }
            pthread_mutex_unlock(&pagMtx);
            return false;
        }
        else if (pages<mypages)
        {

            uint32_t  toppage=-1;
            pthread_mutex_lock(&pagMtx);
            for (uint32_t i = pages;i<mypages;i++ )
            {
                
                if (lv2==0)
                {
                   lv2=1024; 
                }
                lv2--;
                toppage= (((uint32_t *) m_MemStart + ((m_PageTableRoot &ADDR_MASK)>>OFFSET_BITS)*1024)[lv1-1]&ADDR_MASK)>>OFFSET_BITS;
                newpage=(((uint32_t*) m_MemStart + ((((uint32_t*) m_MemStart + ((m_PageTableRoot &ADDR_MASK)>>OFFSET_BITS)*PAGE_DIR_ENTRIES)[lv1-1] &ADDR_MASK)>>OFFSET_BITS)*PAGE_DIR_ENTRIES)[lv2]&ADDR_MASK)>>OFFSET_BITS;
                returnpage(newpage); 
                allmypages--;
                ((uint32_t*) m_MemStart + ((((uint32_t*) m_MemStart + ((m_PageTableRoot &ADDR_MASK)>>OFFSET_BITS)*PAGE_DIR_ENTRIES)[lv1-1] &ADDR_MASK)>>OFFSET_BITS)*PAGE_DIR_ENTRIES)[lv2]=0;
                if (lv2==0)
                {
                    returnpage(toppage); 
                    allmypages--;
                    lv1--;
                    ((uint32_t *) m_MemStart + ((m_PageTableRoot &ADDR_MASK)>>OFFSET_BITS)*1024)[lv1]=0;
                }
            }
            pthread_mutex_unlock(&pagMtx);
            mypages=pages;
            return true;
        }
        else
        {
         return true;   
        }
        return false;
    };
    virtual bool  NewProcess  ( void * processArg, void (* entryPoint) ( CCPU *, void * ), bool copyMem )
    {
        
        try 
        {
            pthread_t thr;
            pthread_attr_t thrAttr;
            pthread_attr_init(&thrAttr);
            pthread_attr_setdetachstate(&thrAttr, PTHREAD_CREATE_DETACHED);
    
            if (copyMem==false && freepages>0)
            {
          
                uint32_t root=add();
                prvok* prvky = new prvok (root*4096+7, processArg, entryPoint, 0);
                pthread_create(&thr, &thrAttr, help, prvky);
        
            }
            else if (copyMem==true && freepages>=allmypages)
            {
       
                pthread_mutex_lock(&pagMtx);
                uint32_t root=add();
                pthread_mutex_unlock(&pagMtx);
                prvok * prvky = new prvok (root*4096+7, processArg, entryPoint, mypages);
                pthread_create(&thr, &thrAttr, help, prvky);
     
            }
            else
            {
                return false;
            }
        
        } 
        catch (...) 
        {
            return false;
        }
        return true;
    };
 CLike(uint8_t   * memStart, uint32_t    pageTableRoot, uint32_t size) :CCPU( memStart,pageTableRoot) 
 {
     
     for (unsigned i=0;i<1024;i++)
    {
    ((uint32_t *) memStart + ((m_PageTableRoot &ADDR_MASK)>>OFFSET_BITS)*1024)[i]=0;
    }
     mypages=0;
     allmypages=0;
     lv1=0;
     lv2=0;

     SetMemLimit ( size );
     //printf("ahoj\n");
}
 ~CLike()
{
    SetMemLimit(0);
}
uint32_t allmypages=0;
uint32_t mypages=0;
uint32_t lv1=0;
uint32_t lv2=0;
 protected:
   /*
    if copy-on-write is implemented:

    virtual bool             pageFaultHandler              ( uint32_t          address,
                                                             bool              write );
    */
};

void *help (void* prvky ) 
{
    prvok * mprvky=(prvok *) prvky;
    CLike* myCCPU=new CLike( (uint8_t*) pamat, mprvky->root, mprvky->mypages);
    mprvky->entryPoint(myCCPU, mprvky->processArg);
    delete myCCPU;
    delete mprvky;
    return NULL;
}

void               MemMgr                                  ( void            * mem,
                                                             uint32_t          totalPages,
                                                             void            * processArg,
                                                             void           (* mainProcess) ( CCPU *, void * ))
{
    pamat=(uint32_t*) mem;
    totalpag=totalPages;
    freepages=totalpag;
    stack = new unsigned [totalpag];
    for (unsigned i=0;i<totalpag;i++)
    {
        stack[i]=i;
    }
    pthread_mutex_lock(&pagMtx);
    uint32_t root=add();
    pthread_mutex_unlock(&pagMtx);
    CLike * myCCPU=new CLike((uint8_t *) mem,root*4096+7,0);
    
    mainProcess(myCCPU,processArg);
    delete myCCPU;
    delete [] stack;
    
    
    
    
}

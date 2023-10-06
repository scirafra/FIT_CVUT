#ifndef __PROGTEST__
#include "flib.h"
#endif //__PROGTEST__

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void tarant_allegra ( int32_t in_file, int32_t out_file, int32_t bytes ){
	int32_t * ar;
	flib_open ( in_file, READ );
	int64_t x=0;
	ar = new int32_t [1002];
	x=flib_read ( in_file, ar, 1002 );
	if (x>1000)
	{
		delete [] ar;
		ar = new int32_t [3000000];
		flib_close ( in_file );
		flib_open ( in_file, READ );
		x=flib_read ( in_file, ar, 3000000 );
		
	}
	flib_close ( in_file );
	qsort(ar, x, sizeof(int32_t),compare);
	flib_open ( out_file, WRITE );
	flib_write ( out_file, ar, x );
	flib_close ( out_file );
	delete [] ar;
}


#ifndef __PROGTEST__

#define SUM_MOD 100000007
uint64_t total_sum_mod;
void create_random(int output, int size){
    total_sum_mod=0;
    flib_open(output, WRITE);
    /* srand(time(NULL)); */
#define STEP 100ll
    int val[STEP];
    for(int i=0; i<size; i+=STEP){
        if(i%STEP==0){
            for(int j=0; j<STEP; ++j){
                val[j]=-1000 + (rand()%(2*1000+1));
                total_sum_mod = (total_sum_mod + val[j]) % SUM_MOD;
            }
        }
        flib_write(output, val, (STEP < size-i) ? STEP : size-i);
    }
    flib_close(output);
}

void tarant_allegra ( int in_file, int out_file, int bytes );

void check_result ( int out_file, int SIZE ){
    flib_open(out_file, READ);
    int q[30], loaded, last=-(1<<30), total=0;
    uint64_t current_sum_mod=0;
    while(loaded = flib_read(out_file, q, 30), loaded != 0){
        total += loaded;
        for(int i=0; i<loaded; ++i){
            if(last > q[i]){
                printf("the result file contains numbers %d and %d on position %d in the wrong order!\n", last, q[i], i-1);
                exit(1);
            }
            last=q[i];
            current_sum_mod = (current_sum_mod + q[i]) % SUM_MOD;
        }
    }
    if(total != SIZE){
        printf("the output contains %d but the input had %d numbers\n", total, SIZE); exit(1);
    }
    if(current_sum_mod != total_sum_mod){
        printf("the output numbers are not the same as the input numbers\n");
        exit(1);
    }
    flib_close(out_file);
}

int main(int argc, char **argv){
    const uint16_t MAX_FILES = 65535;
    flib_init_files(MAX_FILES);
    int INPUT = 0;
    int RESULT = 1;
    int SIZE = 100;

    create_random(INPUT, SIZE);
    tarant_allegra(INPUT, RESULT, 1000);
    check_result(RESULT, SIZE);

    flib_free_files();
    return 0;
}
#endif //__PROGTEST__

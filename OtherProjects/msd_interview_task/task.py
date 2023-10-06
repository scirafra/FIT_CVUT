from collections import Counter
from string import *

filename = "text.txt"
top_results = 10
double_words = []

with open(filename, "r", encoding="utf8") as f:
    
    inp = f.read()
    inp = inp.translate(str.maketrans("", "", punctuation))
    inp = inp.lower().split()
    if len(inp) > 1:

        for i in range(len(inp) - 1):
            double_words.append(inp[i] + " " + inp[i + 1])

        Counter = Counter(double_words)
        most_occur = Counter.most_common(top_results)

        for i in range(min(top_results, len(most_occur))):
            print(most_occur[i])

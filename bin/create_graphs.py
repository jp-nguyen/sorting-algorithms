import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import sys

def plot_timings_from_file(filename):
    timings = pd.read_csv(filename)
    print(timings)
    x = timings['n'].values
    y = timings['seconds'].values

    plt.loglog(x, y, 's')
    plt.show()

if __name__ == "__main__":
    argc = len(sys.argv)
    assert argc == 2, "program only accepts one file"

    plot_timings_from_file(sys.argv[1])
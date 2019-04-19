import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import scipy.interpolate as ip
import sys

def plot_timings_from_file(filename):
    timings = pd.read_csv(filename)
    print(timings)
    sorts = timings['sort'].values
    x = timings['n'].values
    y = timings['seconds'].values

    colors = ["red", "blue", "green"]

    for i, c in enumerate(np.unique(sorts)):
        mask = np.where(sorts == c)[0]
        plt.loglog(x[mask], y[mask], "o", c = colors[i], label=c)

        print(x[mask])
        print(y[mask])
        s = ip.UnivariateSpline(x[mask], y[mask])
        xs = np.linspace(min(x[mask]), max(x[mask]), 100)
        ys = s(xs)

        plt.plot(xs, ys, c = colors[i])
    
    plt.title("Comparison of Sorts on loglog")
    plt.xlabel("Log of Size of Input")
    plt.ylabel("Log of Time in Seconds")
    plt.legend()
    plt.show()

if __name__ == "__main__":
    argc = len(sys.argv)
    assert argc == 2, "program only accepts one file"

    plot_timings_from_file(sys.argv[1])
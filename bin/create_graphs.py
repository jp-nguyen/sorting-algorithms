import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import scipy.interpolate as ip
import sys

def plot_shell_sort_comparisons(filename):
    sorts, x, y = plot_timings_from_file(filename)

    colors = ["red", "blue", "green", "purple"]

def plot_all_comparisons(filename):
    sorts, x, y = plot_timings_from_file(filename)

    colors = ["red", "blue", "green", "purple"]
    fig, ax = plt.subplots(2, 2, figsize = (8, 8))
    ax = ax.flatten()

    for i, c in enumerate(np.unique(sorts)):
        mask = np.where(sorts == c)[0]
        plt.loglog(x[mask], y[mask], "o", alpha = 0.5,c = colors[i], label = c)
        ax[i].set_title("Performance of " + c)
        ax[i].set_xlabel("Log of Size of Input")
        ax[i].set_ylabel("Log of Time in Seconds")
        ax[i].set_xticklabels(ax[i].get_xticks(), fontsize= 5)
        ax[i].set_yticklabels(ax[i].get_yticks(), fontsize= 5)

        ax[3].loglog(x[mask], y[mask], "o", c = colors[i], alpha = 0.5, label = c)

        s = ip.UnivariateSpline(x[mask], y[mask], s = 0)
        xs = np.linspace(min(x[mask]), max(x[mask]), 1000)
        ys = s(xs)
        ax[3].plot(xs, ys, c = colors[i])
    
    ax[3].set_title("Comparison of Sorts on loglog")
    ax[3].set_xlabel("Log of Size of Input")
    ax[3].set_ylabel("Log of Time in Seconds")
    ax[3].set_xticklabels(ax[3].get_xticks())
    ax[3].set_yticklabels(ax[3].get_yticks())
    ax[3].legend()
    
    plt.tight_layout()
    plt.show()
    plt.close()

def plot_timings_from_file(filename):
    timings = pd.read_csv(filename)
    print(timings)

    sorts = timings['sort'].values
    x = timings['n'].values
    y = timings['seconds'].values

    return sorts, x, y

if __name__ == "__main__":
    argc = len(sys.argv)
    assert argc == 2, "program only accepts one file"

    plot_all_comparisons(sys.argv[1])
    #plot_shell_sort_comparisons(sys.argv[1])
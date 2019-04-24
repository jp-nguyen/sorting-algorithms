import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import scipy.interpolate as ip
import sys

def set_up_plot(ax, sort):
    ax.set_title("Performance of " + sort + " sort")
    ax.set_xlabel("Log of Size of Input")
    ax.set_ylabel("Log of Time in Seconds")
    ax.set_xticklabels(ax.get_xticks(), fontsize= 5)
    ax.set_yticklabels(ax.get_yticks(), fontsize= 5)

def get_spline(x, y):
    s = ip.UnivariateSpline(x, y, s = 0)
    xs = np.linspace(min(x), max(x), 1000)
    ys = s(xs)
    return xs, ys

def plot_all_comparisons_on_nearly_sorted(filename):
    sorts, x, y = plot_timings_from_file(filename)

    colors = ["red", "blue", "green", "yellow", "orange", "purple", "brown", "grey", "black"]
    _, ax = plt.subplots(1, 1, figsize = (6, 6))

    for i, s in enumerate(np.unique(sorts)):
        mask = np.where(sorts == s)[0]
        n = len(x[mask]) / 2

        ax.loglog(x[mask][:n], y[mask][:n], "o", markersize = 3, 
                    c = colors[i], label = s)

        xs, ys = get_spline(x[mask][:n], y[mask][:n])
        ax.plot(xs, ys, c = colors[i])
    
    ax.set_title("Comparison of Sorts on Nearly Sorted Input")
    ax.set_xlabel("Log of Size of Input")
    ax.set_ylabel("Log of Time in Seconds")
    ax.set_xticklabels(ax.get_xticks())
    ax.set_yticklabels(ax.get_yticks())
    ax.legend()
    
    plt.savefig("nearly-sorted.png")
    plt.close()

def plot_all_comparisons_on_randomized(filename):
    sorts, x, y = plot_timings_from_file(filename)

    colors = ["red", "blue", "green", "yellow", "orange", "purple", "brown", "grey", "black"]
    _, ax = plt.subplots(1, 1, figsize = (6, 6))

    for i, s in enumerate(np.unique(sorts)):
        mask = np.where(sorts == s)[0]
        n = len(x[mask]) / 2

        ax.loglog(x[mask][n:], y[mask][n:], "o", markersize = 3, 
                    c = colors[i], label = s)

        xs, ys = get_spline(x[mask][n:], y[mask][n:])
        ax.plot(xs, ys, c = colors[i])
    
    ax.set_title("Comparison of Sorts on Randomized Input")
    ax.set_xlabel("Log of Size of Input")
    ax.set_ylabel("Log of Time in Seconds")
    ax.set_xticklabels(ax.get_xticks())
    ax.set_yticklabels(ax.get_yticks())
    ax.legend()
    
    plt.savefig("randomized.png")
    plt.close()

def plot_single_sort(filename):
    sorts, x, y = plot_timings_from_file(filename)
    for s in np.unique(sorts):
        mask = np.where(sorts == s)
        n = len(x[mask]) / 2

        _, ax = plt.subplots(1, 1, figsize = (6, 6))

        ax.loglog(x[mask][:n], y[mask][:n], "o", markersize = 3,
                    c = "blue", label = "Nearly Sorted")
        ax.loglog(x[mask][n:], y[mask][n:], "o", markersize = 3,
                    c = "red", label = "Randomized")
        set_up_plot(ax, s)

        nsxs, nsys = get_spline(x[mask][:n], y[mask][:n])
        urxs, urys = get_spline(x[mask][n:], y[mask][n:])
        ax.plot(nsxs, nsys, c = "blue")
        ax.plot(urxs, urys, c = "red")

        ax.legend()
        #plt.show() 
        plt.savefig("{}.png".format("-".join(s.split(" "))))
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

    #plot_single_sort(sys.argv[1])
    plot_all_comparisons_on_nearly_sorted(sys.argv[1])
    plot_all_comparisons_on_randomized(sys.argv[1])
import math

ALPHAS = [0.001,0.005,0.010,0.05,0.1,0.5]
N = 60000
M = 20000

def main():
    c = lambda a: math.sqrt(-math.log(a/2)/2)
    D = lambda a, m, n: c(a) * math.sqrt((n+m)/(m*n))

    for alpha in ALPHAS:
        print(f"D > {D(alpha,M,N):8.4f} for alpha = {alpha}")

if __name__ == "__main__":
    main()
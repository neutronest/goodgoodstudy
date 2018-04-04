import math
def main():
    T = int(input())
    t = 0
    while t < T:
        res = 0
        A, B = [int(s) for s in input().split(" ")]
        #print(A, B)
        a_sqrt = math.sqrt(A)
        b_sqrt = math.sqrt(B)
        
        n = math.ceil(a_sqrt)
        while n <= math.floor(b_sqrt):
            n_str = str(n)
            flag = 0
            if n > 10:
                for c in n_str:
                    if c != "1" and c != "0" and c != "2":
                        flag = 1
                        break
                if flag != 0:
                    n += 1
                    continue
            if str(n) != (str(n))[::-1]:
                n += 1
                continue

            if str(n*n) == (str(n*n))[::-1]:
                print(n, n*n)
                res += 1
            n += 1
        print("Case #{case_id}: {result}".format(case_id=t+1, result=res))
        t += 1
    return

if __name__ == "__main__":
    main()
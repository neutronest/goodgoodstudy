def main():
    T = int(input())
    case_id = 1
    while case_id <= T:
        seq = input()
        len_seq = len(seq)
        res = 0

        cur = len_seq-1
        while cur >= 0:
            if cur == len_seq-1:
                if seq[cur] == "+":
                    res = 0
                elif seq[cur] == "-":
                    res = 1
                cur -= 1
                continue
            
            if seq[cur] == "+":
                if seq[cur+1] == "+":
                    res = res + 0
                elif seq[cur+1] == "-":
                    res = res + 1
            elif seq[cur] == "-":
                if seq[cur+1] == "+":
                    res = res + 1
                elif seq[cur+1] == "-":
                    res = res + 0
            cur -= 1
        print("Case #{case_id}: {res}".format(case_id=case_id, res=res))
                    
        case_id += 1
    return


if __name__ == "__main__":
    main()
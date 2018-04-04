def main():
    T = int(input())
    case_id = 1
    while case_id <= T:
        num = int(input())
        if num == 0:
            print("Case #{case_id}: INSOMNIA".format(case_id=case_id))
            case_id += 1
            continue
        
        all_nums = []
        res = 0
        cur_num = num
        while len(all_nums) != 10:
            cur_num_str = str(cur_num)
            for digit in cur_num_str:
                if digit not in all_nums:
                    all_nums.append(digit)
            #print(cur_num, all_nums)
            cur_num += num
        res = cur_num-num
        print("Case #{case_id}: {res}".format(case_id=case_id, res=res))
        case_id += 1 
    return


if __name__ == "__main__":
    main()
# coding=gb2312
import random
import re

def read_config(file_name):
    config = {}
    with open(file_name,encoding='utf-8') as f:
        for line in f:
            words = line.strip().split(',')
            config[words[0]] = set(words)
    return config

def main():
    config = read_config('config.ini')
    while True:
        random_group = config[random.choice(list(config))] #先随机选择一组,也是answer_group
        random_word = random.choice(list(random_group))  #然后从随机组中抽出随机的单词
        print(random_word,"请输入它的同义词:")
        user_input = input().strip()
        user_words = {random_word}
        for x in user_input.split(','):
            user_words.add(x.strip()) 
        if user_words == random_group: #答案组和随机组比较user_words == random_group
            print("答案正确")
        else:
            chr = ","
            print("错误，正确答案是:",chr.join(list(random_group)))
        print("**************************************")


if __name__ == '__main__':
    #test()
    main()

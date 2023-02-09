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
        random_group = config[random.choice(list(config))] #�����ѡ��һ��,Ҳ��answer_group
        random_word = random.choice(list(random_group))  #Ȼ���������г������ĵ���
        print(random_word,"����������ͬ���:")
        user_input = input().strip()
        user_words = {random_word}
        for x in user_input.split(','):
            user_words.add(x.strip()) 
        if user_words == random_group: #����������Ƚ�user_words == random_group
            print("����ȷ")
        else:
            chr = ","
            print("������ȷ����:",chr.join(list(random_group)))
        print("**************************************")


if __name__ == '__main__':
    #test()
    main()

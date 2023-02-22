# coding=gb2312
import random
import atexit
import re

class Config:
    def __init__(self,file_path):
        self.file_path = file_path
        self.__configs = {}
        self.words_file = "word.txt"
        self.random_mode = True
        self.seq_num = 1

    def read_config(self):
        with open(self.file_path, 'r',encoding='gb2312') as f:
            lines = f.readlines()
            for line in lines:
                line = line.strip()
                if not line or line.startswith('#'):
                    continue

                parts = line.split("#")
                key_value = parts[0].strip()
                if "=" not in key_value:
                    continue
                config, parameter = key_value.split('=')
                if parameter.strip()!='':
                    self.__configs[config.strip()] = parameter.strip()

        if "WORDSFILE" in self.__configs:
            self.words_file = self.__configs["WORDSFILE"] 
        if "RANDOMMODE" in self.__configs:
            self.random_mode = bool(int(self.__configs["RANDOMMODE"]))
        if "SEQNUM" in self.__configs:
            self.seq_num = int(self.__configs["SEQNUM"])

config = Config("config.ini")


@atexit.register
def clean():
    global config
    newfile=""
    with open(config.file_path, 'r+',encoding='gb2312') as f:
        #定位到那一行，然后修改配置
        modified = False
        while True:
            line = f.readline()
            if not line: 
                if modified:
                    break
                else:
                    newfile += ("SEQNUM="+str(config.seq_num)+"\n")
                    break

            if line.find("SEQNUM")>=0:
                match = re.search("SEQNUM=\s*([0-9]+)\s*",line)
                newfile += (line.replace(match.group(1),str(config.seq_num))) if match else ("SEQNUM="+str(config.seq_num)+"\n")
                modified =True
            else:
                newfile+=line

    with open(config.file_path, 'w+',encoding='gb2312') as f:
        f.write(newfile)

def read_words(file_name):
    words = []
    try:
        with open(file_name,encoding='utf-8') as f:
            for line in f:
                lineWords = line.strip().split(',')
                words.append(set(lineWords))
    except Exception as e:
        print("打开{0}文件失败".format(file_name))
        return None
    return words


def memorize(words):
    answer_group = random.choice(words) if config.random_mode else words[config.seq_num-1] #先选择一组作为answer_group
    random_word = random.choice(list(answer_group))  #抽出随机的单词
    print(random_word,"请输入它的同义词:")
    user_input = input().strip()
    user_words = {random_word}
    for x in user_input.split(','):
        user_words.add(x.strip()) 
    if user_words == answer_group: #答案组和随机组比较user_words == random_group
        print("答案正确")
    else:
        chr = ","
        print("错误，正确答案是:",chr.join(list(answer_group)))
    print("**************************************")
    if not config.random_mode:
        config.seq_num+=1

def main():
    global config
    words = read_words(config.words_file)
    if None == words:
        return
    while True:
        memorize(words)

if __name__ == '__main__':
    config.read_config()
    main()

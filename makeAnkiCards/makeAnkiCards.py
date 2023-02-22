#encoding=gb2312
import genanki
import pandas as pd

#writen by ChatGPT
#pip install pandas genanki ��Ҫ��װpandas��genanki,pandas������Ҫpip��Դ

fileName="538�����cards.csv"
deckName="538Words"
apkgFileName="538Words.apkg"

#1.�� Excel �н���Ƭ����ʹ𰸷ֱ𱣴��ڵ�һ�к͵ڶ����У������ļ�����Ϊ CSV ��ʽ��
#2.ʹ�� Pandas ���ȡ CSV �ļ���������ʹ𰸱����������б��С�
df = pd.read_csv(fileName)
questions = df.iloc[:, 0].tolist()
answers = df.iloc[:, 1].tolist()

#3.ʹ�� genanki �ⴴ��һ�� Anki ģ�壬Ȼ��ѭ����������ʹ��б�Ϊÿ������ʹ𰸴���һ�� Anki ��Ƭ��������Ƭ��ӵ�ģ���С�
model = genanki.Model(
    1607392319,
    'Simple Model',
    fields=[
        {'name': 'Question'},
        {'name': 'Answer'},
    ],
    templates=[
        {
            'name': 'Card 1',
            'qfmt': '{{Question}}',
            'afmt': '{{FrontSide}}<hr id="answer">{{Answer}}',
        },
    ])

deck = genanki.Deck(
    2059400110,
    deckName)

for question, answer in zip(questions, answers):
    note = genanki.Note(
        model=model,
        fields=[question, answer])
    deck.add_note(note)

genanki.Package(deck).write_to_file(apkgFileName)


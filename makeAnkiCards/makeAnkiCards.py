#encoding=gb2312
import genanki
import pandas as pd

#writen by ChatGPT
#pip install pandas genanki 需要安装pandas和genanki,pandas可能需要pip换源

fileName="538考点词cards.csv"
deckName="538Words"
apkgFileName="538Words.apkg"

#1.在 Excel 中将卡片问题和答案分别保存在第一列和第二列中，并将文件保存为 CSV 格式。
#2.使用 Pandas 库读取 CSV 文件，将问题和答案保存在两个列表中。
df = pd.read_csv(fileName)
questions = df.iloc[:, 0].tolist()
answers = df.iloc[:, 1].tolist()

#3.使用 genanki 库创建一个 Anki 模板，然后循环遍历问题和答案列表，为每个问题和答案创建一个 Anki 卡片，并将卡片添加到模板中。
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


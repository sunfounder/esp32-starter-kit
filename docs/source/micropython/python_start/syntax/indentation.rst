インデント
=============

インデントはコード行の先頭の空白を指します。
標準のPythonプログラムと同じように、MicroPythonプログラムも通常は上から下へと実行されます：
それぞれの行を順に走査し、インタプリタで実行してから次の行へと進みます、
まるでShellで一行ずつタイプするかのように。
ただし、命令リストを行ごとにただ閲覧するだけのプログラムはあまり賢くありません - そこでMicroPythonは、Pythonと同じように、プログラム実行の順序を制御する独自の方法を持っています：インデント。

print()の前には少なくとも1つのスペースを入れる必要があります。さもないと"Invalid syntax"（無効な構文）というエラーメッセージが表示されます。スペースはTabキーを均一に押すことで標準化することが一般的に推奨されます。

.. code-block:: python

    if 8 > 5:
    print("Eight is greater than Five!")

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 2
SyntaxError: invalid syntax

同じブロックのコード内で同じ数のスペースを使用しなければ、Pythonはエラーを出します。

.. code-block:: python

    if 8 > 5:
    print("Eight is greater than Five!")
            print("Eight is greater than Five")
            
>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 2
SyntaxError: invalid syntax
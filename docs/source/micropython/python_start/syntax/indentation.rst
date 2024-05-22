.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

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
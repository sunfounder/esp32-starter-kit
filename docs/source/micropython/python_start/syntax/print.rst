.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

Print()
=====================

``print()`` 関数は、指定されたメッセージを画面や他の標準出力デバイスに印刷します。
メッセージは文字列でも、他のオブジェクトでも構いません。オブジェクトは画面に表示する前に文字列に変換されます。

複数のオブジェクトを印刷する:

.. code-block:: python

    print("Welcome!", "Enjoy yourself!")

>>> %Run -c $EDITOR_CONTENT
Welcome! Enjoy yourself!

タプルを印刷する:

.. code-block:: python

    x = ("pear", "apple", "grape")
    print(x)

>>> %Run -c $EDITOR_CONTENT
('pear', 'apple', 'grape')

2つのメッセージを印刷して、セパレータを指定する:

.. code-block:: python

    print("Hello", "how are you?", sep="---")

>>> %Run -c $EDITOR_CONTENT
Hello---how are you?

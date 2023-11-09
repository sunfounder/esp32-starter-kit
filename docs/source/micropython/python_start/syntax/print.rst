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

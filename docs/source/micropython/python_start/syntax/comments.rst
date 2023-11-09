コメント
=============

コード内のコメントは、コードを理解するのに役立ち、全体のコードの可読性を高め、テスト中にコードの一部をコメントアウトして、その部分のコードが実行されないようにします。

単一行コメント
----------------------------

MicroPythonにおける単一行コメントは # で始まり、その後のテキストは行の終わりまでコメントと見なされます。コメントはコードの前後に配置することができます。

.. code-block:: python

    print("hello world") #This is a annotationhello world

>>> %Run -c $EDITOR_CONTENT
hello world

コメントはコードを説明するためのテキストに限られません。コードの一部をコメントアウトして、micropythonがコードを実行しないようにすることもできます。

.. code-block:: python

    #print("Can't run it！")
    print("hello world") #This is a annotationhello world

>>> %Run -c $EDITOR_CONTENT
hello world

複数行コメント
------------------------------

複数行にわたってコメントする場合は、複数の # を使用できます。

.. code-block:: python

    #This is a comment
    #written in
    #more than just one line
    print("Hello, World!")

>>> %Run -c $EDITOR_CONTENT
Hello, World!

または、予想される代わりに複数行の文字列を使用することができます。

MicroPythonは変数に割り当てられていない文字列リテラルを無視するので、複数行の文字列（トリプルクオート）をコードに追加し、その中にコメントを入れることができます：

.. code-block:: python

    """
    This is a comment
    written in
    more than just one line
    """
    print("Hello, World!")

>>> %Run -c $EDITOR_CONTENT
Hello, World!

文字列が変数に割り当てられていない限り、MicroPythonはコードを読んだ後でそれを無視し、あたかも複数行のコメントを作成したかのように扱います。


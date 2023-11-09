関数
==============

MicroPythonにおいて、関数は特定のタスクを実行する関連するステートメントのグループです。

関数はプログラムをより小さなモジュールブロックに分割するのに役立ちます。プランが大きくなるにつれて、関数はそれをより整理され、管理しやすくします。

また、重複を避け、コードを再利用可能にします。

関数の作成
------------------

.. code-block::

    def function_name（parameters)：
        """docstring"""
        statement(s)

* 関数は ``def`` キーワードを使用して定義されます。

* 関数を一意に識別する関数名。関数の命名は変数の命名と同じで、以下のルールに従います。
    
   * 数字、文字、アンダースコアのみを含むことができます。
   * 最初の文字は文字またはアンダースコアでなければなりません。
   * 大文字と小文字を区別します。

* パラメータ（引数）は、値を関数に渡すために使用します。これはオプショナルです。

* コロン（:）は関数ヘッダの終わりを示します。

* オプショナルなドキュメント文字列は、関数の機能を記述するために使用されます。通常、ドキュメント文字列を複数行に拡張できるようにトリプルクオートを使用します。

* 関数の本体を構成する1つ以上の有効なMicropythonステートメント。ステートメントは同じインデントレベル（通常は4スペース）でなければなりません。

* どんな理由があっても、ステートメントを含まない関数がある場合、エラーを避けるためにpassステートメントを入れてください。

* 関数から値を返すオプショナルな ``return`` ステートメント。


関数の呼び出し
-------------------

関数を呼び出すには、関数名の後に括弧を追加します。

.. code-block:: python

    def my_function():
        print("Your first function")

    my_function()

>>> %Run -c $EDITOR_CONTENT
Your first function

returnステートメント
-----------------------

returnステートメントは関数から出て、それが呼び出された場所に戻るために使用されます。

**returnの構文**

.. code-block:: python

    return [expression_list]

このステートメントには、評価されて値を返す式を含むことができます。ステートメントに式がない場合、または ``return`` ステートメント自体が関数内に存在しない場合、関数は ``None`` オブジェクトを返します。

.. code-block:: python

    def my_function():
            print("Your first function")

    print(my_function())

>>> %Run -c $EDITOR_CONTENT
Your first function
None

ここで、 ``None`` は戻り値です。なぜなら ``return`` ステートメントが使用されていないからです。

引数
-------------

情報を引数として関数に渡すことができます。

関数名の後の括弧内に引数を指定します。必要なだけ多くの引数を追加でき、コンマで区切ります。



.. code-block:: python

    def welcome(name, msg):
        """This is a welcome function for
        the person with the provided message"""
        print("Hello", name + ', ' + msg)

    welcome("Lily", "Welcome to China!")

>>> %Run -c $EDITOR_CONTENT
Hello Lily, Welcome to China!

引数の数
*************************

デフォルトでは、関数は正しい数の引数で呼び出されなければなりません。つまり、関数が2つのパラメータを期待している場合、関数を2つの引数で呼び出す必要があります。多くても少なくてもいけません。



.. code-block:: python

    def welcome(name, msg):
        """This is a welcome function for
        the person with the provided message"""
        print("Hello", name + ', ' + msg)

    welcome("Lily", "Welcome to China!")

ここでは、関数welcome()は2つのパラメータを持っています。

この関数を二つの引数で呼び出すと、エラーなくスムーズに機能します。

引数の数が異なる場合、インタープリタはエラーメッセージを表示します。

以下は、この関数を一つの引数と引数なしで呼び出した例と、それぞれのエラーメッセージです。

.. code-block::

    welcome("Lily")＃Only one argument

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 6, in <module>
TypeError: function takes 2 positional arguments but 1 were given

.. code-block::

    welcome()＃No arguments

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 6, in <module>
TypeError: function takes 2 positional arguments but 0 were given


デフォルト引数
*************************

MicroPythonでは、代入演算子(=)を使用してパラメータにデフォルト値を提供することができます。

引数なしで関数を呼び出すと、デフォルト値が使用されます。

.. code-block:: python

    def welcome(name, msg = "Welcome to China!"):
        """This is a welcome function for
        the person with the provided message"""
        print("Hello", name + ', ' + msg)
    welcome("Lily")

>>> %Run -c $EDITOR_CONTENT
Hello Lily, Welcome to China!

この関数では、パラメータ ``name`` にはデフォルト値がなく、呼び出し時に必須です。

一方で、パラメータ ``msg`` のデフォルト値は「中国へようこそ！」です。したがって、呼び出し時にはオプショナルです。値が提供された場合、デフォルト値は上書きされます。

関数の任意の数の引数にデフォルト値を持たせることができます。しかし、デフォルト引数がある場合、右側のすべての引数にもデフォルト値が必要です。

これは、デフォルト引数の後に非デフォルト引数を続けることはできないことを意味します。

例えば、上記の関数ヘッダーを以下のように定義した場合：

.. code-block:: python

    def welcome(name = "Lily", msg):

以下のエラーメッセージを受け取ります：

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
SyntaxError: non-default argument follows default argument


キーワード引数
**************************

特定の値で関数を呼び出すと、これらの値は位置に基づいて引数に割り当てられます。

例えば、上記の関数welcome()で、welcome("Lily", "中国へようこそ")と呼び出したとき、"Lily"の値が ``name`` に、同様に"中国へようこそ"がパラメータ ``msg`` に割り当てられます。

MicroPythonではキーワード引数を使って関数を呼び出すことができます。この方法で関数を呼び出すと、引数の順序（位置）を変更することができます。

.. code-block:: python

    # keyword arguments
    welcome(name = "Lily",msg = "Welcome to China!")

    # keyword arguments (out of order)
    welcome(msg = "Welcome to China！",name = "Lily") 

    #1 positional, 1 keyword argument
    welcome("Lily", msg = "Welcome to China!")

関数呼び出し時に位置引数とキーワード引数を混在させることができることがわかります。しかし、キーワード引数は位置引数の後に来なければならないことを覚えておく必要があります。

キーワード引数の後に位置引数があるとエラーになります。

例えば、関数の呼び出しが以下のようであれば：

.. code-block:: python

    welcome(name="Lily","Welcome to China!")

以下のエラーが発生します：

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 5, in <module>
SyntaxError: non-keyword arg after keyword arg


任意の引数
********************

関数に渡される引数の数が事前にわからない場合があります。

関数定義で、パラメータ名の前にアスタリスク(*)を追加することができます。

.. code-block:: python

    def welcome(*names):
        """This function welcomes all the person
        in the name tuple"""
        #names is a tuple with arguments
        for name in names:
            print("Welcome to China!", name)
            
    welcome("Lily","John","Wendy")

>>> %Run -c $EDITOR_CONTENT
Welcome to China! Lily
Welcome to China! John
Welcome to China! Wendy

ここで、複数の引数で関数を呼び出しました。これらの引数は関数に渡される前にタプルにパックされます。

関数の中では、forループを使用してすべての引数を取り出します。

再帰
----------------
Pythonでは、関数が他の関数を呼び出すことができます。関数が自分自身を呼び出すことも可能です。このタイプの構造は再帰関数と呼ばれます。

これはデータをループして結果に到達するという意味で有利です。

開発者は再帰に非常に注意する必要があります。非常に簡単に終了しない関数を書いたり、過剰なメモリやプロセッサパワーを使用したりすることがあります。しかし、正しく書かれた再帰は、非常に効率的で数学的にエレガントなプログラミングのアプローチになることがあります。

.. code-block:: python

    def rec_func(i):
        if(i > 0):
            result = i + rec_func(i - 1)
            print(result)
        else:
            result = 0
        return result

    rec_func(6)

>>> %Run -c $EDITOR_CONTENT
1
3
6
10
15
21

この例では、rec_func()は自分自身を呼び出すように定義された関数です（「再帰」）。 ``i`` 変数をデータとして使用し、再帰するたびに（-1）減少します。条件が0より大きくない場合（つまり0の場合）、再帰は終了します。

新しい開発者にとっては、どのように動作するかを把握するまでに時間がかかるかもしれませんが、テストして修正することが最善の方法です。

**再帰の利点**

* 再帰関数はコードをクリーンでエレガントにします。
* 複雑なタスクを再帰を使ってよりシンプルなサブ問題に分割することができます。
* いくつかのネストされたイテレーションを使用するよりも、再帰を使ったシーケンス生成が容易です。

**再帰の欠点**

* 再帰の背後にある論理を追うのが時々難しいです。
* 再帰呼び出しは高コスト（非効率的）で、多くのメモリと時間を取ります。
* 再帰関数はデバッグが難しいです。


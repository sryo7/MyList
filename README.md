# List
### MyList.h & .cpp
リストの構造を勉強するために自作した双方向リスト

### Example
```c++
int main(int argc, const char * argv[]) {
    MyList myList;             // MyList
    myList.pushBackNode(0);    // [0]
    myList.pushBackNode(5);    // [0, 5]
    myList.replaceNode(4, 1);  // [4, 5]
    myList.insertNode(2, 1);   // [2, 4, 5]
    myList.insertNode(3, 2);   // [2, 3, 4, 5]
    myList.insertNode(7, 5);   // [2, 3, 4, 5, 7]
    myList.insertNode(8, -1);  // [2, 3, 4, 5, 7, 8]
    myList.insertNode(6, -3);  // [2, 3, 4, 5, 6, 7, 8]
    myList.insertNode(1, -8);  // [1, 2, 3, 4, 5, 6, 7, 8]
    myList.popBackNode();      // [1, 2, 3, 4, 5, 6, 7]
    myList.deleteNode(2);      // [1, 3, 4, 5, 6, 7]
    myList.deleteNode(6);      // [1, 3, 4, 5, 6]
    myList.deleteNode(-1);     // [1, 3, 4, 5]
    myList.deleteNode(-2);     // [1, 3, 5]
    myList.deleteNode(-3);     // [3, 5]
    myList.display();          // "3, 5"と表示される
    return 0;
}
```
### メンバ関数
引数の`index`は負の値を入れると、**後ろから数えて`index`番目**となる

#### `.pushbackNode(int newData)`
- リストの末尾に要素`newData`を追加

#### `.replaceNode(int newData, int index)`
- `index`番目の要素を`newData`に置き換える

#### `.insertNode(int newData, int index)`
- リストの`index`番目に`newData`を挿入

#### `.popBackNode()`
- リストの末尾の要素を削除

#### `.deleteNode(int index)`
- `index`番目の要素を削除

#### `.getData(int index)`
- `index`番目の要素を返す

#### `.getLenght()`
- 要素数を返す

#### `.display()`
- リストの要素を全て表示

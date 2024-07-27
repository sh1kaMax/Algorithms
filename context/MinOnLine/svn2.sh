mkdir lab2svn
cd lab2svn
svnadmin create repository
mkdir main
svn mkdir file:///C:/Users/user/lab2svn/repository/trunk -m "Создание trunk"
svn checkout file:///C:/Users/user/lab2svn/repository/trunk main/trunk
cd main/trunk

echo "0" >> 0.txt
svn add *
svn commit -m "r0" --username=red

cd ../..
svn mkdir file:///C:/Users/user/lab2svn/repository/branch2 -m "Создание branch2"
svn copy file:///C:/Users/user/lab2svn/repository/trunk file:///C:/Users/user/lab2svn/repository/branch2/bottom -m "Создание bottom"

svn checkout file:///C:/Users/user/lab2svn/repository/branch2/bottom main/bottom
cd main/bottom

echo "1" >> 1.txt
svn add *
svn commit -m "r1" --username=blue

cd ../..
svn copy file:///C:/Users/user/lab2svn/repository/branch2/bottom file:///C:/Users/user/lab2svn/repository/branch2/upper -m "Создание upper"
svn checkout file:///C:/Users/user/lab2svn/repository/branch2/upper main/upper
cd main/upper

echo "2" >> 2.txt
svn add *
svn commit -m "r2" --username=blue

cd ../trunk
echo "3" >> 3.txt
svn add *
svn commit -m "r3" --username=red

echo "4" >> 4.txt
svn add *
svn commit -m "r4" --username=red

cd ../upper
echo "5" >> 5.txt
svn add *
svn commit -m "r5" --username=blue

echo "6" >> 6.txt
svn add *
svn commit -m "r6" --username=blue

echo "7" >> 7.txt
svn add *
svn commit -m "r7" --username=blue

echo "8" >> 8.txt
svn add *
svn commit -m "r8" --username=blue

echo "9" >> 9.txt
svn add *
svn commit -m "r9" --username=red

cd ../upper
echo "10" >> 10.txt
svn add *
svn commit -m "r10" --username=blue

cd ../bottom
echo "11" >> 11.txt
svn add *
svn commit -m "r11" --username=blue

cd ../upper
svn up
svn merge file:///C:/Users/user/lab2svn/repository/branch2/bottom
svn add *
svn commit -m "r12" --username=blue

echo "13" >> 13.txt
svn add *
svn commit -m "r13" --username=blue

cd ../trunk
svn up
svn merge file:///C:/Users/user/lab2svn/repository/branch2/upper
svn add *
svn commit -m "r14" --username=red
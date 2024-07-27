git init
git remote add origin https://github.com/mariks1/lab2MiSPI.git
git config user.name "red"
git config user.email red@google.com
mkdir src
echo "0" >> src/0.txt
git add .
git commit -m "r0"
git push -u origin master

git config user.name "blue"
git config user.email blue@google.com
git checkout -b branch2
git pull origin master
echo "1" >> src/1.txt
git add .
git commit -m "r1"
git push origin branch2

git checkout -b branch3
git pull origin branch2
echo "2" >> src/2.txt
git add .
git commit -m "r2"
git push origin branch3

git config user.name "red"
git config user.email red@google.com
git checkout master
git pull origin master
echo "3" >> src/3.txt
git add .
git commit -m "r3"
git push origin master

echo "4" >> src/4.txt
git add .
git commit -m "r4"
git push origin master

git config user.name "blue"
git config user.email blue@google.com
git checkout branch3
git pull origin branch3
echo "5" >> src/5.txt
git add .
git commit -m "r5"
git push origin branch3

echo "6" >> src/6.txt
git add .
git commit -m "r6"
git push origin branch3

echo "7" >> src/7.txt
git add .
git commit -m "r7"
git push origin branch3

echo "8" >> src/8.txt
git add .
git commit -m "r8"
git push origin branch3

git config user.name "red"
git config user.email red@google.com
git checkout master
git pull origin master
echo "9" >> src/9.txt
git add .
git commit -m "r9"
git push origin master

git config user.name "blue"
git config user.email blue@google.com
git checkout branch3
git pull origin branch3
echo "10" >> src/10.txt
git add .
git commit -m "r10"
git push origin branch3

git checkout branch2
git pull origin branch2
echo "11" >> src/11.txt
git add .
git commit -m "r11"
git push origin branch2

echo "12" >> src/11.txt
git add .
git commit -m "r12"
git push origin branch2

git checkout branch3
git merge branch2 -m "Merging two branches -> r13"
git commit -m "r13"
git push origin branch3

git config user.name "red"
git config user.email red@google.com
git checkout master
git pull origin master
git merge branch3 -m "Merging two branches -> r14"
git mergetool
git add .
git commit -m "r14"
git push origin master
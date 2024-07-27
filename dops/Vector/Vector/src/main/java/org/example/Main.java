package org.example;


public class Main {
    public static void main(String[] args) {
        Vector<Integer> myVector = new Vector<>(3, 0);
        myVector.popBack();
        myVector.pushBack(5);
        myVector.insert(3, 3);
        System.out.println(myVector);
        myVector.remove(1);
        myVector.remove(2);
        System.out.println(myVector);
        myVector.set(0, 10);
        System.out.println(myVector.get(0));
    }
}
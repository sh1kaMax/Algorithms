package org.example;


public class Vector<T> {
    private static final int MIN_SIZE = 20;

    private T[] vector;
    private int size;
    private int capacity;

    public Vector(int size, T startValue) {
        this.size = size;
        this.capacity = size;
        vector = (T[]) new Object[size];

        for (int i = 0; i < size; i++) {
            this.vector[i] = startValue;
        }
    }

    public Vector() {
        this.size = 0;
        this.capacity = MIN_SIZE;
        vector = (T[]) new Object[MIN_SIZE];
    }

    public void set(int index, T value) {
        if (!isEmpty()) {
            if (index >= 0 && index <= size - 1) {
                vector[index] = value;
            } else {
                System.out.println("Ошибка: недопустимый индекс!");
            }
        } else {
            System.out.println("Ошибка: vector пустой!");
        }
    }


    public T get(int index) {
        if (!isEmpty()) {
            if (index >= 0 && index <= size - 1) {
                return vector[index];
            } else {
                System.out.println("Ошибка: недопустимый индекс!");
            }
        } else {
            System.out.println("Ошибка: vector пустой!");
        }
        return null;
    }


    public int getSize() {
        return size;
    }


    public boolean isEmpty() {
        return size == 0;
    }

    public void pushBack(T value) {
        if (!isEmpty()) {
            if (size >= capacity) {
                T[] newVector = (T[]) new Object[capacity * 2];
                capacity *= 2;
                for (int i = 0; i < size; i++) {
                    newVector[i] = vector[i];
                }
                vector = newVector;
            }
            vector[size] = value;
            size++;
        } else {
            System.out.println("Ошибка: vector пустой!");
        }
    }

    public void popBack() {
        if (!isEmpty()) {
            size--;
        } else {
            System.out.println("Ошибка: vector пустой!");
        }
    }


    public T back() {
        if (!isEmpty()) {
            return vector[size - 1];
        } else {
            System.out.println("Ошибка: vector пустой!");
            return null;
        }
    }

    public void insert(int index, T value) {
        if (index >= 0 && index <= size) {
            T[] newVector;
            if (size < capacity) {
                newVector = (T[]) new Object[capacity];
            } else {
                newVector = (T[]) new Object[capacity * 2];
                capacity *= 2;
            }

            boolean check = false;
            for (int i = 0; i < size + 1; i++) {
                if (i == index) {
                    newVector[i] = value;
                    check = true;
                } else {
                    if (check) {
                        newVector[i] = vector[i - 1];
                    } else {
                        newVector[i] = vector[i];
                    }
                }
            }
            size++;
            vector = newVector;
        } else {
            System.out.println("Ошибка: недопустимая позиция вставки!");
        }
    }


    public void remove(int index) {
        if (!isEmpty()) {
            if (index >= 0 && index <= size - 1) {
                T[] newVector = (T[]) new Object[capacity];
                boolean check = false;
                for (int i = 0; i < size; i++) {
                    if (i == index) {
                        check = true;
                    } else {
                        if (check) {
                            newVector[i - 1] = vector[i];
                        } else {
                            newVector[i] = vector[i];
                        }
                    }
                }
                size--;
                vector = newVector;
            } else {
                System.out.println("Ошибка: недопустимая позиция удаления!");
            }
        } else {
            System.out.println("Ошибка: vector пустой!");
        }
    }

    public void clear() {
        size = 0;
    }

    @Override
    public String toString() {
        StringBuilder vectorString = new StringBuilder("[");
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                vectorString.append(vector[i].toString());
            } else {
                vectorString.append(vector[i].toString()).append(",").append(" ");
            }
        }
        vectorString.append("]");
        return vectorString.toString();
    }
}

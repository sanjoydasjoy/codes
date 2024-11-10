public class LinkedList_1 {
    public static class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
    public static Node head;
    public static Node tail;
    public static int size;

    
    public void addFirst(int data) {
        // step1 = create new node
        Node newNode = new Node(data);
        size++;

        if (head == null) {
            head = tail = newNode;
            return;
        }

        // step2 - newNode next = head
        newNode.next = head;

        // step3 - head = newNode
        head = newNode;

    }

    public void addLast(int data) {
        // step1 = create new node
        Node newNode = new Node(data);
        size++;

        if (head == null) {
            head = tail = newNode;
            return;
        }

        // step2 - tail next = newNode
        tail.next = newNode;

        // step3 - tail = newNode
        tail = newNode;

    }

    public void addMiddle(int index, int data) {
        if (index == 0) {
            addFirst(data);
            return;
        }
        Node newNode = new Node(data);
        size++;
        Node temp = head;
        int i = 0;
        while (i < index - 1) {
            temp = temp.next;
            i++;
        }
        // i = index-1; temp=prev
        newNode.next = temp.next;
        temp.next = newNode;

    }

    public void print() {
        if (head == null) {
            System.out.println("LL is empty");
            return;
        }
        Node temp = head;
        while (temp != null) {
            System.out.println(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public void removeFirst() {
        if (size == 0) {
            System.out.println("LL is empty");
        } else if (size == 1) {
            head = tail = null;
            size = 0;
        }
        head = head.next;
        size--;
    }

    public void removeLast() {
        if (size == 0) {
            System.out.println("LL is empty");
        } else if (size == 1) {
            head = tail = null;
            size = 0;
        }
        Node prev = head;
        int i = 0;
        while (i < size - 2) {
            prev = prev.next;
            i++;
        }
        prev.next = null;
        tail = prev;
        size--;
    }

    public int itrSearch(int key) {
        Node temp = head;
        int i = 0;

        while (temp != null) {
            if (temp.data == key) { // key found
                return i;
            }
            temp = temp.next;
            i++;
        }

        // key not found
        return -1;
    }

    public int recSearch(int key) {
        Node temp = head;
        int i = 0;

        while (temp != null) {
            if (temp.data == key) { 
                return i;
            }
            temp = temp.next;
            i++;
        }

        // key not found
        return -1;
    }

    public static void main(String args[]) {
        LinkedList_1 ll = new LinkedList_1();

        ll.addFirst(2);
        ll.addFirst(1);
        ll.addLast(3);
        ll.addLast(4);
        ll.addMiddle(2, 9);
        ll.print();
        System.out.println(size);
        // ll.removeFirst();
        // ll.print();

        ll.removeLast();
        ll.print();
        System.out.println(size);

        System.out.println(ll.itrSearch(3));
        System.out.println(ll.itrSearch(10));

    }

}

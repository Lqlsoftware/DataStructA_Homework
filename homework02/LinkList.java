public class LinkList {
    public Node head;
    public Node current;
    private int length;

    // 构造函数 控制台输入
    public void LinkList {
        this.length = 0;
        System.out.println("Input LinkList end with -1");
        Console console = System.console();
        StringBuffer str = console.readLine();
        String num = str.substring(0, str.indexOf(' '));
        str = str.substring(str.indexOf(' ') + 1);
        while (!num.equals("-1")) {
            this.add(num);
            this.length ++;
            num = str.substring(0, str.indexOf(' '));
            str = str.substring(str.indexOf(' ') + 1);
        }
    }
    public int getLength() {
         return this.length;   
    }
    //方法：向链表中添加数据
    public void add(int data) {
        //判断链表为空的时候
        if (head == null) {//如果头结点为空，说明这个链表还没有创建，那就把新的结点赋给头结点
            head = new Node(data);
            current = head;
        } else {
            //创建新的结点，放在当前节点的后面（把新的结点合链表进行关联）
            current.next = new Node(data);
            //把链表的当前索引向后移动一位
            current = current.next;   //此步操作完成之后，current结点指向新添加的那个结点
        }
    }

    //方法：遍历链表（打印输出链表。方法的参数表示从节点node开始进行遍历
    public void print(Node node) {
        if (node == null) {
            return;
        }

        current = node;
        while (current != null) {
            System.out.println(current.data);
            current = current.next;
        }
    }


    class Node {
        //注：此处的两个成员变量权限不能为private，因为private的权限是仅对本类访问。
        int data; //数据域
        Node next;//指针域

        public Node(int data) {
            this.data = data;
        }
    }


    public static void main(String[] args) {
        LinkList list = new LinkList();
        //向LinkList中添加数据
        for (int i = 0; i < 10; i++) {
            list.add(i);
        }

        list.print(list.head);// 从head节点开始遍历输出
    }

}
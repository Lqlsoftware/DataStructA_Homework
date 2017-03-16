import LinkList;

public class  DSA02_2{
    
    public static boolean xyz(LinkList L) {
        Stack s = new Stack();
        // 判断基数个节点还是偶数个节点
        int i = 0, length, flag;
        length = L.getLength();
        flag = length % 2;
    
        // 遍历链表检查是否对称
        L.current = L.current.next;
        while (L.current != NULL) {
            i++;
            if (flag.equals(1) && i.equals(length/2 + 1)) {
                L.current = L.current.next;
                continue;
            }
            else if (i < length/2)
                s.push(L.current.data);
            else if (s.peek().equals(L.current.data))
                s.pop();
            else
                break;
            L.current = L.current.next;
        }
        if (s.empty())
            return 1;
        else
            return 0;
    }

    public static void main(String[] args) {
        // 新建链表
        try {
            LinkList L = new LinkList();
        } catch (Exception e) {
            e.printStackTrace();
        }

        if (xyx(L))
            printf("It's a balance link\n");
        else
            printf("It's not a balance link\n");
    }
}
import java.io.*;
import java.util.*;
import java.lang.*;
public class Test extends PrintWriter { Test() { super(System.out); }static Scanner sc = new Scanner(System.in);final static String inputFile = "src/test.txt";public static void main(String[] $) {Test o = new Test();boolean ok = true;try {File f = new File(inputFile);sc = new Scanner(f);} catch (Exception e) {sc = new Scanner(System.in);ok = false;}if (ok) {try {File f = new File(inputFile);sc = new Scanner(f);} catch (Exception e) {}}o.main();o.flush();}
    void main() {
        int t = 1;
        t = sc.nextInt();
        while(t-- > 0) {
            testcase();
        }
    }
    void testcase() {
        int n = sc.nextInt();
        ArrayList<Integer> a = new ArrayList<>();
        int b = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) b = sc.nextInt();
            a.add(i == 0 ? b : sc.nextInt());
        }
        Collections.sort(a);
        if (a.get(0) < b) {
            println("Alice");
        } else {
            println("Bob");
        }

    }
}
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNextInt()) {
			int a = cin.nextInt();
			BigInteger s = new BigInteger("1");
			for (int i = 1; i <= a; ++i) {
				s = s.multiply(BigInteger.valueOf(i));
			}
			System.out.println(s);
		}
	}
}
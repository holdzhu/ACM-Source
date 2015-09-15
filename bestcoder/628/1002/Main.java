import java.io.*;
import java.util.*;
import java.math.*;

class Main {
	static BigInteger[] a = new BigInteger[101];
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int t = cin.nextInt();
		while (t-- > 0) {
			int n = cin.nextInt();
			for (int i = 0; i < n; ++i) {
				a[i] = cin.nextBigInteger();
			}
			if (a[0].compareTo(BigInteger.ZERO) == 0) {
				boolean flag = true;
				for (int i = 0; i < n; ++i) {
					if (a[i].compareTo(BigInteger.ZERO) != 0) {
						flag = false;
						break;
					}
				}
				System.out.println(flag ? "Yes" : "No");
			} else if (n == 1) {
				System.out.println("Yes");
			} else {
				boolean flag = true;
				for (int i = 0; i < n; ++i) {
					if (a[i].compareTo(BigInteger.ZERO) == 0) {
						flag = false;
						break;
					}
				}
				if (!flag) {
					System.out.println("No");
				} else {
					for (int i = 1; i < n; ++i) {
						if (a[0].multiply(a[i]).compareTo(a[1].multiply(a[i - 1])) != 0) {
							flag = false;
							break;
						}
					}
					System.out.println(flag ? "Yes" : "No");
				}
			}
		}
	}
}
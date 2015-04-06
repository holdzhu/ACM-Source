import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int[] lp = new int[]{1, 1, 2, 6, 4};
		int[] p2 = new int[]{6, 2, 4, 8};
		int[] a = new int[1000];
		while (cin.hasNextBigInteger()) {
			BigInteger b = cin.nextBigInteger();
			if (b.compareTo(BigInteger.ONE) == 0 || b.compareTo(BigInteger.ZERO) == 0) {
				System.out.println(1);
			}
			else {
				int p = 0;
				while (b.compareTo(BigInteger.ZERO) != 0) {
					a[p++] = b.mod(BigInteger.valueOf(5)).intValue();
					b = b.divide(BigInteger.valueOf(5));
				}
				int s = 6;
				for (int i = 0; i < p; ++i) {
					s *= lp[a[i]];
					int t = i * a[i];
					if (t > 0) {
						s *= p2[t % 4];
					}
					s %= 10;
				}
				System.out.println(s);
			}
		}
	}
}
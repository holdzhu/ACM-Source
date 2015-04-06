import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int t = cin.nextInt();
		while (t-- > 0) {
			BigInteger s = BigInteger.ZERO;
			BigInteger n;
			while (!(n = cin.nextBigInteger()).equals(BigInteger.ZERO)) {
				s = s.add(n);
			}
			System.out.println(s);
			if (t > 0) {
				System.out.println();
			}
		}
	}
}
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int t = cin.nextInt();
		while (t-- > 0) {
			int m = cin.nextInt();
			int n = cin.nextInt();
			BigInteger bi = BigInteger.ONE;
			while (n-- > 0) {
				bi = bi.multiply(BigInteger.valueOf(m));
			}
			System.out.println(bi);
		}
	}
}
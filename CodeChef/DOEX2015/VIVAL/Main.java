import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public BigInteger solve(int x, int y, int z) {
		BigInteger rnt = BigInteger.ONE;
		for (int i = x + 1; i <= x + y + z; ++i) {
			rnt = rnt.multiply(BigInteger.valueOf(i));
		}
		for (int i = 1; i <= y; ++i) {
			rnt = rnt.divide(BigInteger.valueOf(i));
		}
		for (int i = 1; i <= z; ++i) {
			rnt = rnt.divide(BigInteger.valueOf(i));
		}
		return rnt;
	}

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int t = cin.nextInt();
		while (t-- > 0) {
			int bx = cin.nextInt();
			int by = cin.nextInt();
			int bz = cin.nextInt();
			int bx1 = cin.nextInt();
			int by1 = cin.nextInt();
			int bz1 = cin.nextInt();
			int bx2 = cin.nextInt();
			int by2 = cin.nextInt();
			int bz2 = cin.nextInt();
		}
	}
}
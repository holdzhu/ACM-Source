import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

	static int cnt;
	static int[] p = new int[1 << 14];
	static int[] id = new int[1 << 14];
	static int[] tmp = new int[14];
	static int[] tmp2 = new int[14];
	static BigInteger[][] d = new BigInteger[135][135];
	static int[] perm = new int[135];
	static BigInteger[][] dp = new BigInteger[301][135];

	public static void main(String[] args)  throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("frequent.in"));
		PrintWriter out = new PrintWriter(new FileWriter("frequent.out"));
		int n, t;
		for (String buf; (buf = br.readLine()) != null && !buf.equals("0 0");) {
			String[] tok = buf.split(" ");
			n = Integer.parseInt(tok[0]);
			t = Integer.parseInt(tok[1]);
			for (int i = 1; i <= n; ++i) {
				out.print(i + " ");
			}
			out.println();
			cnt = 0;
			for (int i = 0; i < (1 << n); ++i) {
				id[i] = -1;
				if ((i & 1) == 0) {
					p[i] = -1;
					continue;
				}
				int pos = 0;
				for (int j = 0; j < n; ++j) {
					tmp[pos] = 1;
					while (j < n - 1 && (i & (1 << (j + 1))) == 0) {
						j++;
						tmp[pos]++;
					}
					pos++;
				}
				Arrays.sort(tmp, 0, pos);
				p[i] = 0;
				int pp = 0;
				for (int j = 0; j < pos; ++j) {
					p[i] |= 1 << pp;
					pp += tmp[j];
				}
				if (p[i] == i) {
					id[i] = cnt;
					perm[cnt++] = i;
				}
			}
			for (int i = 0; i < cnt; ++i) {
				for (int j = 0; j < cnt; ++j) {
					d[i][j] = BigInteger.ZERO;
				}
			}
			for (int i = 0; i < cnt; ++i) {
				int pos = 0;
				for (int j = 0; j < n; ++j) {
					tmp[pos] = 1;
					while (j < n - 1 && (perm[i] & (1 << (j + 1))) == 0) {
						j++;
						tmp[pos]++;
					}
					pos++;
				}
				d[i][i] = d[i][i].add(BigInteger.valueOf(n));
				for (int j = 0; j < pos; ++j) {
					for (int k = 0; k < pos; ++k) {
						if (j == k) {
							int pos2 = 0;
							for (int l = 0; l < pos; ++l) {
								if (l != j)
								{
									tmp2[pos2++] = tmp[l];
								}
							}
							for (int l = 1; l < tmp[j]; ++l) {
								tmp2[pos2++] = l;
								tmp2[pos2++] = tmp[j] - l;
								Arrays.sort(tmp2, 0, pos2);
								int newp = 0;
								int pp = 0;
								for (int l1 = 0; l1 < pos2; ++l1) {
									newp |= 1 << pp;
									pp += tmp2[l1];
								}
								d[i][id[newp]] = d[i][id[newp]].add(BigInteger.valueOf(tmp[j]));
								pos2 -= 2;
							}
						} else {
							int pos2 = 0;
							for (int l = 0; l < pos; ++l) {
								if (l != j && l != k)
								{
									tmp2[pos2++] = tmp[l];
								}
							}
							tmp2[pos2++] = tmp[j] + tmp[k];
							Arrays.sort(tmp2, 0, pos2);
							int newp = 0;
							int pp = 0;
							for (int l = 0; l < pos2; ++l) {
								newp |= 1 << pp;
								pp += tmp2[l];
							}
							d[i][id[newp]] = d[i][id[newp]].add(BigInteger.valueOf(tmp[j] * tmp[k]));
						}
					}
				}
			}
			for (int i = 0; i < cnt - 1; ++i) {
				dp[0][i] = BigInteger.ZERO;
			}
			dp[0][cnt - 1] = BigInteger.ONE;
			for (int i = 1; i <= t; ++i) {
				for (int j = 0; j < cnt; ++j) {
					dp[i][j] = BigInteger.ZERO;
				}
				for (int j = 0; j < cnt; ++j) {
					for (int k = 0; k < cnt; ++k) {
						dp[i][j] = dp[i][j].add(dp[i - 1][k].multiply(d[k][j]));
					}
				}
			}
			BigInteger down = BigInteger.valueOf(n * n).pow(t);
			BigInteger g = down.gcd(dp[t][cnt - 1]);
			out.println(dp[t][cnt - 1].divide(g) + "/" + down.divide(g));
		}
		br.close();
		out.close();
	}

}
#include <cstdio>
#include <cstring>

const int level = 3;
const int levelsquare = level * level;
const char sigmastart = '1';
const int SLOT = 0;
const int ROW = 1;
const int COL = 2;
const int SUB = 3;
const int DIMX = levelsquare * levelsquare * 4;
const int DIMY = levelsquare * levelsquare * levelsquare;
bool pic[levelsquare * levelsquare * levelsquare][levelsquare * levelsquare * 4];
char puzzle[levelsquare][levelsquare + 1];

int encode(int a, int b, int c)
{
	return a * levelsquare * levelsquare + b * levelsquare + c + 1;
}

void decode(int code, int& a, int& b, int& c)
{
	code--;
	c = code % levelsquare;
	code /= levelsquare;
	b = code % levelsquare;
	code /= levelsquare;
	a = code;
}

FILE *fp;

void pixel_write(int i, int j){
    static unsigned char color[3];
    color[0] = !pic[i][j] * 255;
    color[1] = !pic[i][j] * 255;
    color[2] = !pic[i][j] * 255;
    fwrite(color, 1, 3, fp);
}


int main()
{
	memset(pic, 0, sizeof(pic));
	for (int i = 0; i < levelsquare; ++i)
	{
		scanf("%s", puzzle[i]);
	}
	for (int r = 0; r < levelsquare; ++r)
	{
		for (int c = 0; c < levelsquare; ++c)
		{
			for (int v = 0; v < levelsquare; ++v)
			{
				if (puzzle[r][c] < sigmastart || puzzle[r][c] >= sigmastart + levelsquare || puzzle[r][c] == sigmastart + v)
				{
					pic[encode(r, c, v)][encode(SLOT, r, c)] = true;
					pic[encode(r, c, v)][encode(ROW, r, v)] = true;
					pic[encode(r, c, v)][encode(COL, c, v)] = true;
					pic[encode(r, c, v)][encode(SUB, (r / level) * level + c / level, v)] = true;
				}
			}
		}
	}
	fp = fopen("DLXPic.ppm"," wb");
    fprintf(fp, "P6\n%d %d\n255\n", DIMX, DIMY);
    for (int j = 0; j < DIMY; ++j)
    {
    	for (int i = 0; i < DIMX; ++i)
    	{
    		pixel_write(j, i);
    	}
    }
    fclose(fp);
	return 0;
}

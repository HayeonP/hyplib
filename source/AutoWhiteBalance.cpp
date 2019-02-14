void autowb(IplImage* src, IplImage* dst)
{
	double YSum = 0;
	double CbSum = 0;
	double CrSum = 0;
	double n = 0;

	double R, B, G, Y, Cb, Cr;
	double a11, a12, a21, a22, b1, b2, Ar, Ab;
	for (int i = 0; i < src->height; i++)
	{
		for (int j = 0; j < src->width; j++)
		{
			int index = i * src->width * 3 + j * 3;
			unsigned char R = (unsigned char)src->imageData[index + 2];
			unsigned char G = (unsigned char)src->imageData[index + 1];
			unsigned char B = (unsigned char)src->imageData[index];


			Y = 0.299*R + 0.587*G + 0.114*B;
			Cb = -0.1687*R - 0.3313*G + 0.5*B;
			Cr = 0.5*R - 0.4187*G - 0.0813*B;


			if (Y - fabs(Cb) - fabs(Cr) > 100)
			{
				YSum += Y;
				CbSum += Cb;
				CrSum += Cr;
				n++;
			}
		}
	}

	if (n == 0)
	{
		return;
	}

	YSum /= n;
	CbSum /= n;
	CrSum /= n;

	Y = YSum;
	Cb = CbSum;
	Cr = CrSum;

	a11 = -0.1687*Y - 0.2365*Cr;
	a12 = 0.5*Y + 0.866*Cb;
	a21 = 0.5*Y + 0.701*Cr;
	a22 = -0.0813*Y - 0.1441*Cb;

	b1 = 0.3313*Y - 0.114*Cb - 0.2366*Cr;
	b2 = 0.4187*Y - 0.1441*Cb - 0.299*Cr;


	Ar = (a22*b1 - a12 * b2) / (a11*a22 - a12 * a21);
	Ab = (a21*b1 - a11 * b2) / (a21*a12 - a11 * a22);

	for (int i = 0; i < src->height; i++)
	{
		for (int j = 0; j < src->width; j++)
		{
			int index = i * src->width * 3 + j * 3;
			float R = (unsigned char)src->imageData[index + 2];
			float G = (unsigned char)src->imageData[index + 1];
			float B = (unsigned char)src->imageData[index];

			R *= Ar;
			if (R > 255.)
			{
				R = 255.;
			}
			else if (R < 0.)
			{
				R = 0.;
			}

			if (G > 255.)
			{
				G = 255.;
			}
			else if (G < 0.)
			{
				G = 0.;
			}

			B *= Ab;
			if (B > 255.)
			{
				B = 255.;
			}
			else if (B < 0.)
			{
				B = 0.;
			}

			dst->imageData[i* dst->width * 3 + j * 3 + 2] = (unsigned char)R;
			dst->imageData[i* dst->width * 3 + j * 3 + 1] = (unsigned char)G;
			dst->imageData[i* dst->width * 3 + j * 3] = (unsigned char)B;
		}
	}
}
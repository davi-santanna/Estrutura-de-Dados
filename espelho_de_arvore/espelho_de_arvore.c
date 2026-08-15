void main ()
{
	void inverte_filho(NO* no)
		{
			if(no->dir||no->esq)
				{
					NO* temp = no->dir;
					no->dir = no->esq;
					no->esq = temp;
					inverte_filho(no->esq);
					inverte_filho(no->dir);					
				}
			else return;
		}
	return;
}
#include<stdio.h>
#include<stdlib.h>
//Lista enlazada circular 
typedef struct list_circle{
	int dato;
	struct list_circle*sig;
}list_circle;
list_circle*search(list_circle*a,int n)//Busca un elemento en la lista y retorna el puntero con ese nodo
{
	list_circle*head=a->sig;
	list_circle*b=a->sig;
	while(b->sig!=head && b->dato!=n)
	{
		b=b->sig;
	}
	head=NULL;
	free(head);
	return b;
}
list_circle*insert(list_circle*a,int n)//Inserta un elemento y retorna el ultimo nodo de la lista
{	
	if(a==NULL)
	{
		list_circle*a=(list_circle*) malloc(sizeof(list_circle));
		a->dato=n;
		a->sig=NULL;
		return a;
	}
	else
	{
		if(a->sig==NULL)
		{
			list_circle*b=(list_circle*) malloc(sizeof(list_circle));
			b->dato=n;
			a->sig=b;
			b->sig=a;
			return b;
		}
		else
		{
			list_circle*b=(list_circle*) malloc(sizeof(list_circle));
			b->dato=n;
			b->sig=a->sig;
			a->sig=b;
			return b;
		}

	}
}
list_circle*delete(list_circle*a,list_circle*b)//A es el ultimo nodo de la lista y B el nodo a eliminar
{
	list_circle*c=a;
	if(a->sig=a->sig)
	{
		free(a);
		return NULL;
	}	
	while(c->sig!=b)
	{
		c=c->sig;
	}
	if(b==a->sig)//B es el primer elemento de la lista
	{
		a->sig=b->sig;
		c=b->sig;
		free(b);
		return a;
	}
	else if(b==a)//B es el final de la lista
	{
		c->sig=a->sig;
		free(b);
		return c;
	}
	else//B es otro nodo entre medio
	{	
		c->sig=b->sig;
		free(b);
		return a;
	}
}
void mostrar(list_circle*a)
{
	list_circle*head=a->sig;
	list_circle*b=a->sig;
	printf("Datos de la list circular:\n");
	while(b->sig!=head)
	{
		printf("Dato: %d\n",b->dato);
		printf("Direccion del nodo siguiente: %p\n",b->sig);
		b=b->sig;
	}
	printf("Dato: %d\n",b->dato);
	printf("Direccion del nodo siguiente: %p\n",b->sig);
}
int main(void)
{
	list_circle*a=NULL;//Cabeza de list_circle;
	int n,x,op;//n=numero de elementos y x = elemento,z=Eliminar
	do{
		printf("Lista circular enlazada simple\n\t");
		printf("0° Para terminar\n\t");
		printf("1° Ingresar\n\t");
		printf("2° Eliminar\n\t");
		printf("3° Mostrar\n\n");
		printf("Ingrese una opcion\n");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("Ingrese el numero de elementos a ingresar en la lista\n");
				scanf("%d",&n);
				do{
					printf("Ingrese un numero entero\n");
					scanf("%d",&x);
					a=insert(a,x);//Despues de la segunda inserción el puntero a empieza a ser el final de la lista
					n--;
				}while(n);
				break;
			case 2:
				printf("Ingrese un numero a eliminar\n");
				scanf("%d",&x);
				a=delete(a,search(a,x));
				break;
			case 3:
				mostrar(a);
				break;
			default:
				printf("Opcion no valida");
				break;
		}
	}while(op);
	while(a)
	{
		a=delete(a,a);	
	}	
	return 0;
}

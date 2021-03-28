using namespace std;
#include </usr/include/gtk-3.0/gtk/gtk.h>
#include <string.h>
#include </usr/include/gtk-3.0/gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <sstream>


//widgets interface
GtkBuilder *builder;
GtkWidget *window;
GtkWidget *ContenedorPrincipal;
GtkWidget *btnAccion;
GtkWidget *scrolledConsola;
GtkWidget *consola;
GtkWidget *mostrador;
GtkWidget *scrolled2;
GtkWidget *btnVerArbol;
GtkWidget *label1;
GtkWidget *lblText;
GtkWidget *btnModo;
GtkWidget *DocumentChooser;
GtkTextBuffer *buffer;
gchar *nameFile;

vector<string> split (const string &s, char delim);
void on_Principal_destroy_event();
static void on_consola_key_press_event(GtkWidget *widget, GdkEventKey *event);
void on_Accion_clicked();
int verTamSplit(char *token);
char *Sustituir(char *cadena, char cambiar, char sustituir);
void ReconocedorSentencia(char* sentencia);
int contarLineas();
string leerArchivo();
void on_Accion_clicked();
char *cat(char *s1, char *s2);


int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    // builder = gtk_builder_new();
    // gtk_builder_add_from_file (builder, "glade/interface.glade", NULL);
    // Update October 2019: The line below replaces the 2 lines above
    builder = gtk_builder_new_from_file("glade/Interface.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //AGREGANDO EVENTO ENTER A LA CONSOLA
    
    //g_object_unref(builder);
    ContenedorPrincipal = GTK_WIDGET(gtk_builder_get_object(builder, "ContenedorPrincipal"));
    btnAccion = GTK_WIDGET(gtk_builder_get_object(builder, "btnAccion"));
    scrolledConsola = GTK_WIDGET(gtk_builder_get_object(builder, "scrolledConsola"));
    consola = GTK_WIDGET(gtk_builder_get_object(builder, "consola"));
    scrolled2 = GTK_WIDGET(gtk_builder_get_object(builder, "scrolled2"));
    mostrador = GTK_WIDGET(gtk_builder_get_object(builder, "mostrador"));
    btnVerArbol = GTK_WIDGET(gtk_builder_get_object(builder, "btnVerArbol"));
    label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
    DocumentChooser = GTK_WIDGET(gtk_builder_get_object(builder, "DocumentChooser"));
    btnModo = GTK_WIDGET(gtk_builder_get_object(builder, "btnModo"));
    lblText = GTK_WIDGET(gtk_builder_get_object(builder, "lblText"));

    g_signal_connect (consola, "key-release-event", G_CALLBACK (on_consola_key_press_event),NULL);
     g_signal_connect (btnAccion, "clicked", G_CALLBACK (on_Accion_clicked),NULL);

    gtk_builder_connect_signals(builder, NULL);
    G_MODULE_EXPORT void my_callback(void);
    gtk_widget_show(window);
    
    gtk_main();
    return EXIT_SUCCESS;
}


// called when window is closed
void on_Principal_destroy_event()
{
    gtk_main_quit();
}

void on_consola_key_press_event(GtkWidget *widget, GdkEventKey *event)
{
    GtkTextIter start, end;
    GtkTextBuffer *textbuffer = NULL;
    g_assert (GTK_IS_TEXT_VIEW (consola));
    guint keyval;
    gdk_event_get_keyval((GdkEvent *)event, &keyval);
    if (keyval == GDK_KEY_Return || keyval == GDK_KEY_KP_Enter)
    {
        textbuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (consola));
        gtk_text_buffer_get_bounds (textbuffer, &start, &end);
        gchar *text;
        text = gtk_text_buffer_get_text (textbuffer, &start, &end, FALSE);
        vector<string> vec= split (text, '\n');
        int z = vec.size();
        if(z>0){
            string tx =  vec[z-1];
            cout<< tx<<"\n";
        }
        
        //ReconocedorSentencia(  sentencia);
        gtk_label_set_text(GTK_LABEL(label1), (const gchar *)"ingreso");
    }
}

void on_Accion_clicked()
{    
    buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (consola));
    string testoCompleto ="";
    nameFile = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(DocumentChooser));
    if (gtk_switch_get_active(GTK_SWITCH(btnModo))&& nameFile != NULL)
    {
       testoCompleto = leerArchivo();
       char buffer2[500];
        strcpy(buffer2,testoCompleto.c_str());
       cout << testoCompleto <<"\n";
       gtk_text_buffer_set_text(buffer,buffer2, -1);

    }
    printf("99 %s\n", nameFile);
}

string leerArchivo()
{
    if (gtk_switch_get_active(GTK_SWITCH(btnModo)))
    {
        
        string c2 ="";
        string c3=" ";
        string testoCompleto= "";
        char*lin;
        int i = 0;
        //const gchar *a_nombre=gtk_entry_get_text(GTK_ENTRY(consola));
        int numeroLineas = contarLineas();
        string lineas[numeroLineas];
        FILE *abrir;
        char *textoLeido[numeroLineas];
        char texto[500];
        abrir = fopen(nameFile, "r");
       
        do {
            lin= fgets(texto, 50, abrir);
            //gtk_text_buffer_set_text(buffer, texto, -1);
            if(lin!=NULL){
                lineas[i] = lin;
                textoLeido[i] = lin;
                testoCompleto = textoLeido[i];
                testoCompleto= c2 + testoCompleto;
                c3 = c3 + testoCompleto;
                
                //printf("141 %s--- %i\n", testoCompleto, i);
                cout<<testoCompleto<<"----=\n";
            }
            i++;
        }while (lin!=NULL);
         printf("saliendo while %s-- ",textoLeido[0]);
        fclose(abrir);
        //printf("saliendo while %s-- ",c3);
       cout<<"saliendo while"<<lineas[0]<<"----=\n";
        testoCompleto = c3;
        return testoCompleto;
    }
    else
    {
        return "";
    }
}

string leerArchivo22()
{
    if (gtk_switch_get_active(GTK_SWITCH(btnModo)))
    {
        
        int numeroLineas = contarLineas();
        int c = 0;
        char *devf;
        char texto[100];
        //const gchar *a_nombre=gtk_entry_get_text(GTK_ENTRY(consola));
        FILE *abrir;
        char *textoLeido[numeroLineas];
        abrir = fopen(nameFile, "r");
        do
       {
        devf = fgets(texto,100,abrir);
        printf("163 %s\n", devf);
        // Aqui puedes poner código para procesar la cadena leida ..
        textoLeido[c]= devf;
        c++;
       } while (devf!=NULL);

        fclose(abrir);
        string testoCompleto= "";
        int k = numeroLineas;
        int j = 0;
        char c2[100];
        char c3[100];
        while (k > 0)
        {
            //sprintf(testoCompleto, "%s%s", testoCompleto, textoLeido[j] );
            strcpy(c2, testoCompleto.c_str());
            strcpy(c3, textoLeido[j]);
            strcat( c2, c3 );
            j++;
            k--;
        }
        testoCompleto = c2;
        return testoCompleto;
    }
    else
    {
        return "";
    }

}


int contarLineas()
{
    char ca;
    int cont=0;

    FILE *puntero;
    puntero = fopen(nameFile, "r");
    while (1)
    {
        ca = fgetc(puntero);
        if (ca == '\n')
        {
            cont++;
        }
        if (ca == EOF)
        { //Si el caracter es end of file imprimimos el contador y salimos del while
            printf("211 %i\n", cont);
            return cont;
        }
    }
}
void ReconocedorSentencia(string  sentencia)
{
    sentencia = regex_replace(sentencia, regex("\\("), "");
    sentencia = regex_replace(sentencia, regex(")"), "");
    vector<string> token = split(sentencia, ',');
    if(token.size()==2){
        
    }else if(token.size()==3){

    }else if(token.size()==4){

    }
}

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

char *Sustituir(char *cadena, char cambiar, char sustituir)
{
    int y = strlen(cadena) - 1;
    int i;
    for (i = 0; i <= y; i++)
    { //recorremos la cadena
        if (cadena[i] == cambiar)
        {                           //compara
            cadena[i] = sustituir; //cambia el valor si lo encuentra
        }                           //end if
    }                               //end for

    printf("\n239 %s ", cadena); //muestra en pantalla la nueva cadena
    return cadena;
}

int verTamSplit(char *token){
    int i=0;
    if(token!=NULL){
        while(token != NULL){
            i++;
        }
    }
    return i;
}



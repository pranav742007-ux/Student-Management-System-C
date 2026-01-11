#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void addstudent(int n);
void NewFunction(FILE *file);
void viewdetail();
void searchbyprn(char *prnsearch);
void editstudent(char *prnsearch);
void deletebyprn(char *prnsearch);
void displaymenu();
typedef struct studentdetail{
  char name[30];
   char PRN[15];
   char contact[14];
   char year[5];
   char email[30];
   int rollno;
   int stream;
   float cgpa;
}detail;
int main(){
    int choice;
    //  Check if the file exists by trying to open it for reading
    FILE *check = fopen("student entry.txt", "r");
    
    if (check == NULL) {
        //  File doesn't exist, so create it and write headers
        FILE *file = fopen("student entry.txt", "w");
        if (file != NULL) {
            fprintf(file, "------------------------------------------Student Details------------------------------------------------------\n");
            fprintf(file, "   StudentName   | PRN Number | Roll no. | Stream  |   Current Year  |   Email id      |  contact no.  |  CGPA   | \n");
            fclose(file);
        }
    } else {
        // File exists
        fclose(check);
    }
    while(1){
        displaymenu();      //function call to display menu
        printf("enter your choice:\n");
        scanf("%d",&choice);
        while(getchar() != '\n');  // Clear input buffer

        switch(choice){
            case 1 :{ 
                      int n;      // new element added
                      printf("enter number of student to add;\n");
                      scanf("%d",&n);
                      while(getchar() != '\n');  // Clear input buffer
                      addstudent(n);     //function call to add details
                      break;
            }
            case 2 : viewdetail();       //function call to view details
                     break;
            case 3 :{printf("enter PRN number to search:\n");
                     char prnsearch[10];
                     scanf("%s",prnsearch);
                     while(getchar() != '\n');  // Clear input buffer
                     searchbyprn(prnsearch);   //funnction call to search  detail by useing PRN no.      
                     break;
                    }
            case 4 :{printf("enter PRN number to edit:\n");
                     char prnsearch[10];
                     scanf("%s",prnsearch);
                     while(getchar() != '\n');  // Clear input buffer
                     editstudent(prnsearch);   //function call to edit student details     
                     break;
                    }
            case 5 : { printf("enter your PRN no.:\n");
                      char prnsearch[10];
                      scanf("%s",prnsearch);
                      while(getchar() != '\n');  // Clear input buffer
                      deletebyprn(prnsearch);   //function call to delete student details     
                      break;
                 }
            case 6 : exit(0);      //exit from program
                     break;
            default : printf("invalid input\n");    
        }
    }
    return 0;

}
void displaymenu(){
    printf("------- Welcome to Student Entry System -------\n");
    printf("1.Add student details\n");
    printf("2.View student details\n");
    printf("3.Search student by PRN number\n");
    printf("4.Edit student details\n");
    printf("5.Delete student details\n");
    printf("6.Exit\n");
}
void addstudent(int n){
   FILE *file =fopen("student entry.txt","a");
   detail entry[100];  // array of structure
     for(int i=0;i<n;i++){ 
   // starting loop
   
   printf("Enter your name (20):\n");           // input name
   scanf("%[^\n]",entry[i].name);
   while(getchar() != '\n');  // Clear input buffer
      fprintf(file,"%s|",entry[i].name);    // write name to file
   
      printf("enter your PRN number:\n");     // input PRN
   scanf("%14s",entry[i].PRN);
   while(getchar() != '\n');  // Clear input buffer
     fprintf(file,"%s|",entry[i].PRN);   // write PRN to file
   
     printf("Enter your Roll no.:\n");       // input roll no.
   scanf("%d",&entry[i].rollno);
   while(getchar() != '\n');  // Clear input buffer
    fprintf(file,"%d|",entry[i].rollno);     // write roll no. to file
  
    printf("Choose your stream:\n");
    printf("1.computer science\n"); 
    printf("2.IT\n");
    printf("3.AIDS\n");
    printf("4.ENTC\n");
    printf("5.Electrical\n");
    printf("6.instrumentation\n");
    scanf("%d",&entry[i].stream);     // input stream
    while(getchar() != '\n');  // Clear input buffer
          switch(entry[i].stream){
            case 1: fprintf(file,"CS|");break;
            case 2 : fprintf(file,"IT|");break;
            case 3 : fprintf(file,"AIDS|");break;
            case 4 : fprintf(file,"ENTC|");break;
            case 5 : fprintf(file,"Electrical|");break;
            case 6 : fprintf(file,"Instrumentation|");break;
            default : printf("invalid input\n");
          }                                              // write stream to file
  
          printf("your are Studing in which year?\n");       // input year
   scanf("%s",entry[i].year);
   while(getchar() != '\n');  // Clear input buffer
     fprintf(file,"%3s|",entry[i].year);            // write year to file
  
     printf("Enter your Email id:\n");           //input email
     scanf("%s",entry[i].email);
   while(getchar() != '\n');  // Clear input buffer
     fprintf(file,"%s|",entry[i].email);          //write email to file
  
     printf("Enter your contact number:\n");           // input contact no.
   scanf("%10s",entry[i].contact);
   while(getchar() != '\n');  // Clear input buffer
     fprintf(file,"%s|",entry[i].contact);       // write contact no. to file
   
     printf("Enter your CGPA score :\n");             // input CGPA
   scanf("%f",&entry[i].cgpa);
   while(getchar() != '\n');  // Clear input buffer
     fprintf(file,"%.2f\n",entry[i].cgpa);           // write CGPA to file
 
     //display enterd details
    printf("---------Entered details----------\n");
    printf("Name:%s\n",entry[i].name);
    printf("PRN no.:%s\n",entry[i].PRN);
    printf("Roll no.:%d\n",entry[i].rollno);
    printf("Stream: %d\n",entry[i].stream);
    printf("Current year: %s\n",entry[i].year);
    printf("Email: %s\n",entry[i].email);
    printf("Contact no.: %s\n",entry[i].contact);
    printf("CGPA : %.2f\n",entry[i].cgpa);
       //end of loop 
        }
        NewFunction(file); // Flush the buffer to ensure data is written
        fclose(file);
}

void NewFunction(FILE *file)
{
  fflush(file);   // Ensure all data is written to the file
}

  void viewdetail(){
    char ch;
    FILE *file = fopen("student entry.txt","r");
    if(file == NULL){
        printf("file not found\n");
        return;
    }
    while((ch = fgetc(file)) != EOF){   
        printf("%c",ch);                        // read and display file content
    }
    fclose(file);
  }

  void searchbyprn(char *prnsearch) {
    FILE *file = fopen("student entry.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }

    detail entry;
    char line[1024];
    char stream_str[50];
    int found = 0;

    // Skip the two header lines you print in addstudent()
    fgets(line, sizeof(line), file);
    fgets(line, sizeof(line), file);

    // Read and parse records
    /* * Reads student records line-by-line using '|' as a delimiter.
       * Format: [Name]|[PRN]|[Roll]|[Stream]|[Year]|[Email]|[Contact]|[CGPA]
       * 1. ' %[^|]' : Skips leading whitespace/newlines, then reads text until a '|'.
       * 2. '|'      : Matches and skip character to move to the next.
       * 3. '== 8'   : Data Check all 8 fields were successfully read 
       * and assigned. If a line is malformed or empty, the loop stops.
     */
   while (fscanf(file, " %[^|]|%[^|]|%d|%[^|]|%[^|]|%[^|]|%[^|]|%f\n", 
              entry.name, entry.PRN, &entry.rollno, stream_str, 
              entry.year, entry.email, entry.contact, &entry.cgpa) == 8)    
              {
        
        // Use strcasecmp to check if the PRN matches
        if (strcasecmp(entry.PRN, prnsearch) == 0) {                //here strcasecmp function is used to compare two strings with ascii value 
            printf("\n--- Student Details Found ---\n");
            printf("Name:        %s\n", entry.name);
            printf("PRN:         %s\n", entry.PRN);
            printf("Roll No:     %d\n", entry.rollno);
            printf("Stream:      %s\n", stream_str);
            printf("Year:        %s\n", entry.year);
            printf("Email:       %s\n", entry.email);
            printf("Contact:     %s\n", entry.contact);
            printf("CGPA:        %.2f\n", entry.cgpa);
            printf("-----------------------------\n");
            found = 1;
            break; // Exit loop once found
        }
    }

        if (!found) {
        printf("Student with PRN %s not found.\n", prnsearch);
    }

    fclose(file);
}

void editstudent(char *prnsearch){
    FILE *file = fopen("student entry.txt", "r");
    FILE *tempfile = fopen("student entry.txt.tmp", "w");
    detail entry;
    char line[1024], stream_str[20];
    int found = 0, choice;
    
    if (file == NULL){
        printf("file not found\n");
        return;
    }
    
    // Copy header lines to temp file
    fgets(line, sizeof(line), file);
    fputs(line, tempfile);
    fgets(line, sizeof(line), file);
    fputs(line, tempfile);
    
    // Read and update records - format: name\t|PRN\t|rollno\t|stream|year\t|email\t|contact\t|cgpa
   while (fscanf(file, " %[^|]|%[^|]|%d|%[^|]|%[^|]|%[^|]|%[^|]|%f\n", 
              entry.name, entry.PRN, &entry.rollno, stream_str, 
              entry.year, entry.email, entry.contact, &entry.cgpa) == 8)  {
        
        
        
        if (strcasecmp(entry.PRN, prnsearch) == 0) {             //here strcasecmp function is used to compare two strings with ascii value
            printf("---------Student found! What do you want to edit?-----------\n");
            printf("1.Name\n");
            printf("2.Roll no.\n");
            printf("3.Stream\n");
            printf("4.Year\n");
            printf("5.Email\n");
            printf("6.Contact\n");
            printf("7.CGPA\n");
            printf("8.Done editing\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            while(getchar() != '\n');
            
            switch(choice){
                case 1:
                    printf("Enter new name: ");
                    scanf("%s", entry.name);
                    while(getchar() != '\n');
                    break;
                case 2:
                    printf("Enter new roll no.: ");
                    scanf("%d", &entry.rollno);
                    while(getchar() != '\n');
                    break;
                case 3:
                    printf("Choose new stream (1-6): ");
                    scanf("%d", &entry.stream);
                    while(getchar() != '\n');
                    break;
                case 4:
                    printf("Enter new year: ");
                    scanf("%s", entry.year);
                    while(getchar() != '\n');
                    break;
                case 5:
                    printf("Enter new email: ");
                    scanf("%s", entry.email);
                    while(getchar() != '\n');
                    break;
                case 6:
                    printf("Enter new contact: ");
                    scanf("%s", entry.contact);
                    while(getchar() != '\n');
                    break;
                case 7:
                    printf("Enter new CGPA: ");
                    scanf("%f", &entry.cgpa);
                    while(getchar() != '\n');
                    break;
                case 8:
                    break;
                default:
                    printf("Invalid choice\n");
            }
            found = 1;
        }
        
        // Convert stream string to integer for switch
        if (strcmp(stream_str, "CS") == 0) entry.stream = 1;
        else if (strcmp(stream_str, "IT") == 0) entry.stream = 2;
        else if (strcmp(stream_str, "AIDS") == 0) entry.stream = 3;
        else if (strcmp(stream_str, "ENTC") == 0) entry.stream = 4;
        else if (strcmp(stream_str, "Electrical") == 0) entry.stream = 5;
        else if (strcmp(stream_str, "Instrumentation") == 0) entry.stream = 6;
        
        // Get stream string
        switch(entry.stream){
            case 1: strcpy(stream_str, "CS");break;           /*  here strcpy function is used to copy string from one variable to another */
            case 2: strcpy(stream_str, "IT");break;                  
            case 3: strcpy(stream_str, "AIDS");break;
            case 4: strcpy(stream_str, "ENTC");break;
            case 5: strcpy(stream_str, "Electrical");break;
            case 6: strcpy(stream_str, "Instrumentation");break;
        }
        
        // Write record to temp file in the same format - only stream name, no number
        fprintf(tempfile, "%s\t|%s\t|%d\t|%s|%s\t|%s\t|%s\t|%.2f\n",
                entry.name, entry.PRN, entry.rollno, stream_str,
                entry.year, entry.email, entry.contact, entry.cgpa);
    }
    
    fclose(file);
    fclose(tempfile);
    
    if(found){
        remove("student entry.txt");                                // Delete original file
        rename("student entry.txt.tmp", "student entry.txt");         // Rename temp file to original file name
        printf("Student details updated successfully!\n");
    } else {
        printf("Student with PRN %s not found\n", prnsearch);
        remove("student entry.txt.tmp");                                  // Delete temp file if no changes were made
    }
}

  void deletebyprn(char *prnsearch){
    FILE *file = fopen("student entry.txt", "r");
    FILE *tempfile = fopen("student entry.txt.tmp", "w");
    detail entry;
    char line[1024], stream_str[20];
    int found = 0;
    
    if (file == NULL){
        printf("file not found\n");
        return;
    }
    
    // Copy header lines to temp file
    fgets(line, sizeof(line), file);
    fputs(line, tempfile);
    fgets(line, sizeof(line), file);
    fputs(line, tempfile);
    
    // Read and copy records - format: name\t|PRN\t|rollno\t|stream|year\t|email\t|contact\t|cgpa
    while (fscanf(file, "%[^\t]\t|%[^\t]\t|%d\t|%[^|]|%[^\t]\t|%[^\t]\t|%s\t|%f", 
                  entry.name, entry.PRN, &entry.rollno, stream_str,
                  entry.year, entry.email, entry.contact, &entry.cgpa) == 8) {
        
        if (strcasecmp(entry.PRN, prnsearch) == 0) {
            found = 1;
            continue; // Skip writing this record to delete it
        } else{
            // Convert stream string to integer for proper stream string handling
            if (strcmp(stream_str, "CS") == 0) entry.stream = 1;
            else if (strcmp(stream_str, "IT") == 0) entry.stream = 2;
            else if (strcmp(stream_str, "AIDS") == 0) entry.stream = 3;
            else if (strcmp(stream_str, "ENTC") == 0) entry.stream = 4;
            else if (strcmp(stream_str, "Electrical") == 0) entry.stream = 5;
            else if (strcmp(stream_str, "Instrumentation") == 0) entry.stream = 6;
        
        // Write record to temp file
        fprintf(tempfile, "%s\t|%s\t|%d\t|%s|%s\t|%s\t|%s\t|%.2f\n",
                entry.name, entry.PRN, entry.rollno, stream_str,
                entry.year, entry.email, entry.contact, entry.cgpa);
    }
}
    
    fclose(file);
    fclose(tempfile);
    
    if(found){
        remove("student entry.txt");                                // Delete original file
        rename("student entry.txt.tmp", "student entry.txt");         // Rename temp file to original file name
        printf("Student with PRN %s deleted successfully!\n", prnsearch);
    } else {
        printf("Student with PRN %s not found\n", prnsearch);
        remove("student entry.txt.tmp");                                  // Delete temp file if no changes were made
    }
  }
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
// To reduce errors and improve code readability, I've decided to divide this program into multiple functions
// instead of just using main function for everything

// Function that clears input buffer (absolute must for this program since it uses fgets)
void enhanced_remover() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Function that removes newline character from input (also a must when using fgets)
void newline_remover(char *str)
{
    str[strcspn(str, "\n")] = 0;
}

// Function that displays the welcome message and waits for a second
void welcome()
{
    printf("|------------------------------------------------------|\n|             Welcome to i3wm configurator             |\n| Refer to the i3 user guide if you have any questions |\n|------------------------------------------------------|\n");
    sleep(1);
}

// Function that handles font configuration
int fonts()
{
    // Required strings
    char font_type[13];
    char font_pango[129];
    char font_x[129];
    // For fprintf
    FILE *fptr = NULL;
    // Pretty self-explanatory from now on
    printf("X core fonts or pango (choose pango if unsure): ");
    fgets(font_type, sizeof(font_type), stdin);
    newline_remover(font_type);
    if (strcasecmp (font_type, "pango") == 0)
    {
        printf("Enter font (example: 'DejaVu Sans Mono 10'): ");
        fgets(font_pango, sizeof(font_pango), stdin);
        newline_remover(font_pango);
        fptr = fopen("config", "w");
        fprintf(fptr, "font %s\n", font_pango);
        fclose(fptr);
        printf("Font selection successful\n");
    }
    else if (strcasecmp (font_type, "X core fonts") == 0)
    {
        printf("Enter font description (example --> '-misc-fixed-medium-r-normal--13-120-75-75-C-70-iso10646-1'): ");
        fgets(font_x, sizeof(font_x), stdin);
        newline_remover(font_x);
        fptr = fopen("config", "w");
        fprintf(fptr, "font %s\n", font_x);
        fclose(fptr);
        printf("Font selection successful\n");
    }
    // Exit in case X core fonts or pango is not entered
    else
    {
        printf("Unknown font type - It should be either pango or X core fonts");
        exit(1);
    }
    return 1;
}

void configuration_options()
{
    // Required long integers
    long border_size;
    long float_min_size_x, float_min_size_y, float_max_size_x, float_max_size_y;
    long urgency_delay, gaps_size, gaps_outer;
    // Required for strtol
    char buffer[1025];
    char *endptr;
    // The various configuration options
    char default_orientation[11];
    char workspace_layout[9];
    char title_align[7];
    char default_border_type[7];
    char hide_edge_borders[14];
    char mouse_warping[7];
    char popup_fullsrc[17];
    char focus_wrapping[10];
    char activation_focus[7];
    char tiling_drag[9];
    char gaps[10];
    char smart_gaps[14];
    char temp_str[4];
    // For fprintf
    FILE *fptr = NULL;

    printf("Enter minimum floating window width size: ");
    fgets(buffer, sizeof(buffer), stdin);
    float_min_size_x = strtol(buffer, &endptr, 10);

    printf("Enter minimum floating window height size: ");
    fgets(buffer, sizeof(buffer), stdin);
    float_min_size_y = strtol(buffer, &endptr, 10);
    fptr = fopen("config", "a");
    fprintf(fptr, "floating_minimum_size %ld x %ld\n", float_min_size_x, float_min_size_y);
    fclose(fptr);

    printf("Enter maximum floating window width size: ");
    fgets(buffer, sizeof(buffer), stdin);
    float_max_size_x = strtol(buffer, &endptr, 10);

    printf("Enter maximum floating window height size: ");
    fgets(buffer, sizeof(buffer), stdin);
    float_max_size_y = strtol(buffer, &endptr, 10);
    fptr = fopen("config", "a");
    fprintf(fptr, "floating_maximum_size %ld x %ld\n", float_max_size_x, float_max_size_y);
    fclose(fptr);

    printf("Enter default orientation for new workspaces (horizontal|vertical|auto, choose auto if unsure): ");
    fgets(default_orientation, sizeof(default_orientation), stdin);
    newline_remover(default_orientation);
    fptr = fopen("config", "a");
    fprintf(fptr, "default_orientation %s\n", default_orientation);
    fclose(fptr);

    printf("Enter layout mode for new containers (default|stacking|tabbed): ");
    fgets(workspace_layout, sizeof(workspace_layout), stdin);
    newline_remover(workspace_layout);
    fptr = fopen("config", "a");
    fprintf(fptr, "workspace_layout %s\n", workspace_layout);
    fclose(fptr);

    printf("Enter window title alignment (left|center|right): ");
    fgets(title_align, sizeof(title_align), stdin);
    newline_remover(title_align);
    fptr = fopen("config", "a");
    fprintf(fptr, "title_align %s\n", title_align);
    fclose(fptr);

    printf("Enter default border style for new windows ↓\nThis will be used for both normal and floating windows. (normal|none|pixel): ");
    fgets(default_border_type, sizeof(default_border_type), stdin);
    newline_remover(default_border_type);
    if (strcmp(default_border_type, "normal") == 0 || strcmp(default_border_type, "pixel") == 0)
        {
            printf("Enter default border size: ");
            fgets(buffer, sizeof(buffer), stdin);
            border_size = strtol(buffer, &endptr, 10);
            fptr = fopen("config", "a");
            fprintf(fptr, "default_border %s %ld\n", default_border_type, border_size);
            fclose(fptr);
            fptr = fopen("config", "a");
            fprintf(fptr,"default_floating_border %s %ld\n", default_border_type, border_size);
            fclose(fptr);
        }
    else if (strcmp(default_border_type, "none") == 0)
        {

            fptr = fopen("config", "a");
            fprintf(fptr, "default_border %s\n", default_border_type);
            fclose(fptr);
        }
    printf("Hiding borders adjacent to the screen edges (none|vertical|horizontal|both|smart|smart_no_gaps): ");
        fgets(hide_edge_borders, sizeof(hide_edge_borders), stdin);
        newline_remover(hide_edge_borders);
        fptr = fopen("config", "a");
        fprintf(fptr, "hide_edge_borders %s\n", hide_edge_borders);
        fclose(fptr);

        sleep(1);
        printf("Window specific commands (such as for_window, no_focus, assign) will be added later.\n");
        printf("The same goes for startup programs.\n");
        sleep(1);

        printf("Focus follows mouse (yes-no): ");
        fgets(temp_str, sizeof(temp_str), stdin);
        newline_remover(temp_str);
        if (strcmp(temp_str, "yes") == 0)
        {
            fptr = fopen("config", "a");
            fprintf(fptr, "focus_follows_mouse yes\n");
            fclose(fptr);
        }
        else if (strcmp(temp_str, "no") == 0)
        {
            fptr = fopen("config", "a");
            fprintf(fptr, "focus_follows_mouse no\n");
            fclose(fptr);
        }

        printf("Mouse warping (output|none): ");
        fgets(mouse_warping, sizeof(mouse_warping), stdin);
        newline_remover(mouse_warping);
        fptr = fopen("config", "a");
        fprintf(fptr, "mouse_warping %s\n", mouse_warping);
        fclose(fptr);

        printf("Popups during fullscreen mode (smart|ignore|leave_fullscreen|all): ");
        fgets(popup_fullsrc, sizeof(popup_fullsrc), stdin);
        newline_remover(popup_fullsrc);
        fptr = fopen("config", "a");
        fprintf(fptr, "popup_during_fullscreen %s\n", popup_fullsrc);
        fclose(fptr);

        printf("Focus wrapping (yes|no|force|workspace): ");
        fgets(focus_wrapping, sizeof(focus_wrapping), stdin);
        newline_remover(focus_wrapping);
        fptr = fopen("config", "a");
        fprintf(fptr, "focus_wrapping %s\n", focus_wrapping);
        fclose(fptr);

        printf("Force xinerama (yes-no) (write no if you don't know what it is): ");
        fgets(temp_str, sizeof(temp_str), stdin);
        newline_remover(temp_str);
        if (strcmp(temp_str, "yes") == 0)
        {
            fptr = fopen("config", "a");
            fprintf(fptr, "force_xinerama yes\n");
            fclose(fptr);
        }
        else if (strcmp(temp_str, "no") == 0)
        {
            fptr = fopen("config", "a");
            fprintf(fptr, "force_xinerama no\n");
            fclose(fptr);
        }

        printf("Automatic back-and-forth when switching to the current workspace (yes-no): ");
        fgets(temp_str, sizeof(temp_str), stdin);
        newline_remover(temp_str);
        if (strcmp(temp_str, "yes") == 0)
        {
            fptr = fopen("config", "a");
            fprintf(fptr,"workspace_auto_back_and_forth yes\n");
            fclose(fptr);
        }

        else if (strcmp(temp_str, "no") == 0)
        {
            fptr = fopen("config", "a");
            fprintf(fptr,"workspace_auto_back_and_forth no\n");
            fclose(fptr);
        }
        printf("Delaying urgency hint reset on workspace change (in ms) (the default is 500): ");
        fgets(buffer, sizeof(buffer), stdin);
        urgency_delay = strtol(buffer, &endptr, 10);
        fptr = fopen("config", "a");
        fprintf(fptr,"force_display_urgency_hint %ld ms\n", urgency_delay);
        fclose(fptr);

        printf("Focus on window activation (smart|urgent|focus|none): ");
        fgets(activation_focus, sizeof(activation_focus), stdin);
        newline_remover(activation_focus);
        fptr = fopen("config", "a");
        fprintf(fptr,"focus_on_window_activation %s\n", activation_focus);
        fclose(fptr);

        printf("Drawing marks on window decoration (yes-no): ");
        fgets(temp_str, sizeof(temp_str), stdin);
        newline_remover(temp_str);
        if (strcmp(temp_str, "yes") == 0)
        {
            fptr = fopen("config", "a");
            fprintf(fptr,"show_marks yes\n");
            fclose(fptr);
        }
        else if (strcmp(temp_str, "no") == 0)
        {
            fptr = fopen("config", "a");
            fprintf(fptr,"show_marks no\n");
            fclose(fptr);
        }
        printf("Tiling drag (off|modifier|titlebar): ");
        fgets(tiling_drag, sizeof(tiling_drag), stdin);
        newline_remover(tiling_drag);
        fptr = fopen("config", "a");
        fprintf(fptr,"tiling_drag %s\n", tiling_drag);
        fclose(fptr);

        printf("Inner gap size for all windows (0 to disable ig): ");
        fgets(buffer, sizeof(buffer), stdin);
        gaps_size = strtol(buffer, &endptr, 10);
        fptr = fopen("config", "a");
        fprintf(fptr,"gaps inner %ld\n", gaps_size);
        fclose(fptr);

        printf("Outer gap type (outer|horizontal|vertical|top|left|bottom|right): ");
        fgets(gaps, sizeof(gaps), stdin);
        newline_remover(gaps);
        printf("Outer gap size (0 to disable ig): ");
        fgets(buffer, sizeof(buffer), stdin);
        gaps_outer = strtol(buffer, &endptr, 10);
        fptr = fopen("config", "a");
        fprintf(fptr,"gaps %s %ld\n", gaps, gaps_outer);
        fclose(fptr);

        printf("Smart gaps (on|off|inverse_outer): ");
        fgets(smart_gaps, sizeof(smart_gaps), stdin);
        newline_remover(smart_gaps);
        fptr = fopen("config", "a");
        fprintf(fptr,"smart_gaps %s\n", smart_gaps);
        fclose(fptr);
        printf("i3wmconfigurator does not support changing keyboard or mouse bindings at this time. (I'm lazy)\n");
        sleep(1);
}

void colors()
{
    // Various colors used by i3wm

    // For focused windows
    long bg, fg, border, indicator, child_border;

    // For focused but inactive windows
    long bg_in, fg_in, border_in, indicator_in, child_border_in;

    // For unfocused windows
    long bg_un, fg_un, border_un, indicator_un, child_border_un;

    // For urgent windows
    long bg_urg, fg_urg, border_urg, indicator_urg, child_border_urg;

    // For placeholder windows
    long bg_ph, fg_ph, child_border_ph;

    // Standard background color sitting below the client window
    long background;

    // For strtol, again
    char buffer[1025];
    char *endptr;

    // For yes-no questions
    char temp_str[4];

    printf("Enter border color for focused windows (hex code): #");
    fgets(buffer, sizeof(buffer), stdin);
    border = strtol(buffer, &endptr, 16);
    printf("Enter background color for focused windows (hex code): #");
    fgets(buffer, sizeof(buffer), stdin);
    bg = strtol(buffer, &endptr, 16);
    printf("Enter foreground color for focused windows (hex code): #");
    fgets(buffer, sizeof(buffer), stdin);
    fg = strtol(buffer, &endptr, 16);
    printf("Enter indicator color for focused windows (hex code): #");
    fgets(buffer, sizeof(buffer), stdin);
    indicator = strtol(buffer, &endptr, 16);
    printf("Enter child_border color for focused windows (the color around the child window is the child_border) (hex code): #");
    fgets(buffer, sizeof(buffer), stdin);
    child_border = strtol(buffer, &endptr, 16);
    printf("For focused windows ↓\nBorder color: #%06lx\nBackground color: #%06lx\nForeground color: #%06lx\nIndicator color: #%06lx\nchild_border color: #%06lx\n", border, bg, fg, indicator, child_border);
    printf("Are you sure? (yes-no): ");
    fgets(temp_str, sizeof(temp_str), stdin);
    newline_remover(temp_str);
    if (strcmp (temp_str, "yes") == 0)
        {
            printf("Enter border color for focused but inactive windows (hex code): #");
            fgets(buffer, sizeof(buffer), stdin);
            border_in = strtol(buffer, &endptr, 16);
            printf("Enter background color for focused but inactive windows (hex code): #");
            fgets(buffer, sizeof(buffer), stdin);
            bg_in = strtol(buffer, &endptr, 16);
            printf("Enter foreground color for focused but inactive windows (hex code): #");
            fgets(buffer, sizeof(buffer), stdin);
            fg_in = strtol(buffer, &endptr, 16);
            printf("Enter indicator color for focused but inactive windows (hex code): #");
            fgets(buffer, sizeof(buffer), stdin);
            indicator_in = strtol(buffer, &endptr, 16);
            printf("Enter child_border color for focused but inactive windows (the color around the child window is the child_border) (hex code): #");
            fgets(buffer, sizeof(buffer), stdin);
            child_border_in = strtol(buffer, &endptr, 16);
            printf("For focused but inactive windows ↓\nBorder color: #%06lx\nBackground color: #%06lx\nForeground color: #%06lx\nIndicator color: #%06lx\nchild_border color: #%06lx\n", border_in, bg_in, fg_in, indicator_in, child_border_in);
            printf("Are you sure? (yes-no): ");
            fgets(temp_str, sizeof(temp_str), stdin);
            newline_remover(temp_str);
            if (strcmp (temp_str, "yes") == 0)
            {
                printf("Enter border color for unfocused windows (hex code): #");
                fgets(buffer, sizeof(buffer), stdin);
                border_un = strtol(buffer, &endptr, 16);
                printf("Enter background color for unfocused windows (hex code): #");
                fgets(buffer, sizeof(buffer), stdin);
                bg_un = strtol(buffer, &endptr, 16);
                printf("Enter foreground color for unfocused windows (hex code): #");
                fgets(buffer, sizeof(buffer), stdin);
                fg_un = strtol(buffer, &endptr, 16);
                printf("Enter indicator color for unfocused windows (hex code): #");
                fgets(buffer, sizeof(buffer), stdin);
                indicator_un = strtol(buffer, &endptr, 16);
                printf("Enter child_border color for unfocused windows (the color around the child window is the child_border) (hex code): #");
                fgets(buffer, sizeof(buffer), stdin);
                child_border_un = strtol(buffer, &endptr, 16);
                printf("For unfocused windows ↓\nBorder color: #%06lx\nBackground color: #%06lx\nForeground color: #%06lx\nIndicator color: #%06lx\nchild_border color: #%06lx\n", border_un, bg_un, fg_un, indicator_un, child_border_un);
                printf("Are you sure? (yes-no): ");
                fgets(temp_str, sizeof(temp_str), stdin);
                newline_remover(temp_str);
                if (strcmp (temp_str, "yes") == 0)
                {
                    printf("Enter border color for urgent windows (hex code): #");
                    fgets(buffer, sizeof(buffer), stdin);
                    border_urg = strtol(buffer, &endptr, 16);
                    printf("Enter background color for urgent windows (hex code): #");
                    fgets(buffer, sizeof(buffer), stdin);
                    bg_urg = strtol(buffer, &endptr, 16);
                    printf("Enter foreground color for urgent windows (hex code): #");
                    fgets(buffer, sizeof(buffer), stdin);
                    fg_urg = strtol(buffer, &endptr, 16);
                    printf("Enter indicator color for urgent windows (hex code): #");
                    fgets(buffer, sizeof(buffer), stdin);
                    indicator_urg = strtol(buffer, &endptr, 16);
                    printf("Enter child_border color for urgent windows (the color around the child window is the child_border) (hex code): #");
                    fgets(buffer, sizeof(buffer), stdin);
                    child_border_urg = strtol(buffer, &endptr, 16);
                    printf("For urgent windows ↓\nBorder color: #%06lx\nBackground color: #%06lx\nForeground color: #%06lx\nIndicator color: #%06lx\nchild_border color: #%06lx\n", border_urg, bg_urg, fg_urg, indicator_urg, child_border_urg);
                    printf("Are you sure? (yes-no): ");
                    fgets(temp_str, sizeof(temp_str), stdin);
                    newline_remover(temp_str);
                    if (strcmp (temp_str, "yes") == 0)
                    {
                        printf("Enter background color for placeholder windows (hex code): #");
                        fgets(buffer, sizeof(buffer), stdin);
                        bg_ph = strtol(buffer, &endptr, 16);
                        printf("Enter foreground color for placeholder windows (hex code): #");
                        fgets(buffer, sizeof(buffer), stdin);
                        fg_ph = strtol(buffer, &endptr, 16);
                        printf("Enter child_border color for placeholder windows (the color around the child window is the child_border) (hex code): #");
                        fgets(buffer, sizeof(buffer), stdin);
                        child_border_ph = strtol(buffer, &endptr, 16);
                        printf("For placeholder windows ↓\nBackground color: #%06lx\nForeground color: #%06lx\nchild_border color: #%06lx\n", bg_ph, fg_ph, child_border_ph);
                        printf("Are you sure? (yes-no): ");
                        fgets(temp_str, sizeof(temp_str), stdin);
                        newline_remover(temp_str);
                        if (strcmp (temp_str, "yes") == 0)
                        {
                            printf("(This is the background color which will be used to paint the background of the client window on top of which the client will be rendered.)\n(Only clients which do not cover the whole area of this window expose the color.)\nEnter background color (hex code): #");
                            fgets(buffer, sizeof(buffer), stdin);
                            background = strtol(buffer, &endptr, 16);
                            printf("Background color: #%06lx\n", background);
                            printf("Are you sure? (yes-no): ");
                            fgets(temp_str, sizeof(temp_str), stdin);
                            newline_remover(temp_str);
                            if (strcmp (temp_str, "yes") == 0)
                            {
                                FILE *fptr;
                                fptr = fopen("config", "a");
                                fprintf(fptr, "# class                 border  backgr. text    indicator child_border\nclient.focused          #%06lx #%06lx #%06lx #%06lx   #%06lx\nclient.focused_inactive #%06lx #%06lx #%06lx #%06lx   #%06lx\nclient.unfocused        #%06lx #%06lx #%06lx #%06lx   #%06lx\nclient.urgent           #%06lx #%06lx #%06lx #%06lx   #%06lx\nclient.placeholder      #000000 #%06lx #%06lx #000000   #%06lx\nclient.background       #%06lx\n", border, bg, fg, indicator, child_border, border_in, bg_in, fg_in, indicator_in, child_border_in, border_un, bg_un, fg_un, indicator_un, child_border_un, border_urg, bg_urg, fg_urg, indicator_urg, child_border_urg, bg_ph, fg_ph, child_border_ph, background);
                                fclose(fptr);
                                printf("Done, now copy the config file to ~/.config/i3/config\n");
                            }
                        }
                    }
                }
            }
        }
}

int main(void)
    {
      welcome();
      fonts();
      configuration_options();
      colors();
      return 0;
    }
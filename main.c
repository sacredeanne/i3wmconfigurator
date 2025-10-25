#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(void)
{
    int bg, fg, border, indicator, child_border, bg_in, fg_in, border_in, indicator_in, child_border_in, bg_un, fg_un, border_un, indicator_un, child_border_un, bg_urg, fg_urg, border_urg, indicator_urg, child_border_urg, bg_ph, fg_ph, child_border_ph, background, border_size = 0, font_size = 0, float_min_size_x = 0, float_min_size_y = 0, float_max_size_x = 0, float_max_size_y = 0, urgency_delay = 0, gaps_size = 0, gaps_outer = 0;
    char temp_str[6];
    char font_temp[13];
    char font_name[129];
    char font_type[6];
    char font_option[17];
    char font_x[129];
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
    FILE *fptr = NULL;
    printf("|------------------------------------------------------|\n|             Welcome to i3wm configurator             |\n| Refer to the i3 user guide if you have any questions |\n|------------------------------------------------------|\n");
    sleep(1);
    printf("X-core-fonts or pango (choose pango if unsure):");
    scanf("%12s", font_temp);
    if (strcmp (font_temp, "pango") == 0)
    {
        printf("Enter font name: ");
        scanf("%128s", font_name);
        printf("Enter font type (Sans,Serif): ");
        scanf("%5s", font_type);
        printf("Is it a mono font? (true-false): ");
        scanf("%5s", temp_str);
        if (strcmp (temp_str, "true") == 0)
        {
            printf("Enter font option (like Bold, Regular, etc.): ");
            scanf("%12s", font_option);
            printf("Enter font size: ");
            scanf("%d", &font_size);
            fptr = fopen("config", "w");
            fprintf(fptr, "font pango:%s %s Mono %s %d\n", font_name, font_type, font_option, font_size);
            fclose(fptr);
        }
        else if (strcmp (temp_str, "false") == 0)
        {
            printf("Enter font option (like Bold, Regular, etc.): ");
            scanf("%12s", font_option);
            printf("Enter font size: ");
            scanf("%d", &font_size);
            fptr = fopen("config", "w");
            fprintf(fptr, "font pango:%s %s %s %d\n", font_name, font_type, font_option, font_size);
            fclose(fptr);
        }
        else
        {
            return 0;
        }
    }
    else if (strcmp (font_temp, "X-core-fonts") == 0)
    {
        printf("Enter font description (example --> '-misc-fixed-medium-r-normal--13-120-75-75-C-70-iso10646-1'): ");
        scanf("%128s", font_x);
        fptr = fopen("config", "w");
        fprintf(fptr, "font %s\n", font_x);
        fclose(fptr);
    }
    else
    {
        return 0;
    }
    printf("i3wmconfigurator does not support changing keyboard or mouse bindings at this time. (I'm lazy)\n");
    sleep(1);
    printf("Enter minimum floating window width size: ");
    scanf("%d", &float_min_size_x);
    printf("Enter minimum floating window height size: ");
    scanf("%d", &float_min_size_y);
    fptr = fopen("config", "a");
    fprintf(fptr, "floating_minimum_size %d x %d\n", float_min_size_x, float_min_size_y);
    fclose(fptr);
    printf("Enter maximum floating window width size: ");
    scanf("%d", &float_max_size_x);
    printf("Enter maximum floating window height size: ");
    scanf("%d", &float_max_size_y);
    fptr = fopen("config", "a");
    fprintf(fptr, "floating_maximum_size %d x %d\n", float_max_size_x, float_max_size_y);
    fclose(fptr);
    printf("Enter default orientation for new workspaces (horizontal|vertical|auto, choose auto if unsure): ");
    scanf("%10s", default_orientation);
    fptr = fopen("config", "a");
    fprintf(fptr, "default_orientation %s\n", default_orientation);
    fclose(fptr);
    printf("Enter layout mode for new containers (default|stacking|tabbed): ");
    scanf("%8s", workspace_layout);
    fptr = fopen("config", "a");
    fprintf(fptr, "workspace_layout %s\n", workspace_layout);
    fclose(fptr);
    printf("Enter window title alignment (left|center|right): ");
    scanf("%6s", title_align);
    fptr = fopen("config", "a");
    fprintf(fptr, "title_align %s\n", title_align);
    fclose(fptr);
    printf("Enter default border style for new windows (normal|none|pixel): ");
    scanf(" %6s", default_border_type);
    printf("This will be used for both normal and floating windows.\n");
    sleep(1);
    if (strcmp(default_border_type, "normal") == 0 || strcmp(default_border_type, "pixel") == 0)
    {
        printf("Enter default border size: ");
        scanf("%d", &border_size);
        fptr = fopen("config", "a");
        fprintf(fptr, "default_border %s %d\n", default_border_type, border_size);
        fclose(fptr);
        fptr = fopen("config", "a");
        fprintf(fptr,"default_floating_border %s %d\n", default_border_type, border_size);
        fclose(fptr);
    }
    else if (strcmp(default_border_type, "none") == 0)
    {

        fptr = fopen("config", "a");
        fprintf(fptr, "default_border %s\n", default_border_type);
        fclose(fptr);
    }

    printf("Hiding borders adjacent to the screen edges (none|vertical|horizontal|both|smart|smart_no_gaps): ");
    scanf("%13s", hide_edge_borders);
    fptr = fopen("config", "a");
    fprintf(fptr, "hide_edge_borders %s\n", hide_edge_borders);
    fclose(fptr);

    printf("Window specific commands (such as for_window, no_focus, assign) will be added later.\n");
    printf("The same goes for executing programs at startup.\n");

    sleep(1);

    printf("Focus follows mouse (true-false): ");
    scanf("%5s", temp_str);
    if (strcmp(temp_str, "true") == 0)
    {
        fptr = fopen("config", "a");
        fprintf(fptr, "focus_follows_mouse yes\n");
        fclose(fptr);
    }
    else if (strcmp(temp_str, "false") == 0)
    {
        fptr = fopen("config", "a");
        fprintf(fptr, "focus_follows_mouse no\n");
        fclose(fptr);
    }
    else
    {
        return 0;
    }

    printf("Mouse warping (output|none): ");
    scanf("%6s", mouse_warping);
    fptr = fopen("config", "a");
    fprintf(fptr, "mouse_warping %s\n", mouse_warping);
    fclose(fptr);

    printf("Popups during fullscreen mode (smart|ignore|leave_fullscreen|all): ");
    scanf("%16s", popup_fullsrc);
    fptr = fopen("config", "a");
    fprintf(fptr, "popup_during_fullscreen %s\n", popup_fullsrc);
    fclose(fptr);

    printf("Focus wrapping (yes|no|force|workspace): ");
    scanf("%9s", focus_wrapping);
    fptr = fopen("config", "a");
    fprintf(fptr, "focus_wrapping %s\n", focus_wrapping);
    fclose(fptr);

    printf("Force xinerama (true-false) (write false if you don't know what it is): ");
    scanf("%5s", temp_str);
    if (strcmp(temp_str, "true") == 0)
    {
        fptr = fopen("config", "a");
        fprintf(fptr, "force_xinerama yes\n");
        fclose(fptr);
    }

    else if (strcmp(temp_str, "false") == 0)
    {
        fptr = fopen("config", "a");
        fprintf(fptr, "force_xinerama no\n");
        fclose(fptr);
    }
    else
    {
        return 0;
    }

    printf("Automatic back-and-forth when switching to the current workspace (true-false): ");
    scanf("%5s", temp_str);
    if (strcmp(temp_str, "true") == 0)
    {
        fptr = fopen("config", "a");
        fprintf(fptr,"workspace_auto_back_and_forth yes\n");
        fclose(fptr);
    }

    else if (strcmp(temp_str, "false") == 0)
    {
        fptr = fopen("config", "a");
        fprintf(fptr,"workspace_auto_back_and_forth no\n");
        fclose(fptr);
    }
    else
    {
        return 0;
    }

    printf("Delaying urgency hint reset on workspace change (in ms) (the default is 500): ");
    scanf("%d", &urgency_delay);
    fptr = fopen("config", "a");
    fprintf(fptr,"force_display_urgency_hint %d ms\n", urgency_delay);
    fclose(fptr);

    printf("Focus on window activation (smart|urgent|focus|none): ");
    scanf("%6s", activation_focus);
    fptr = fopen("config", "a");
    fprintf(fptr,"focus_on_window_activation %s\n", activation_focus);
    fclose(fptr);

    printf("Drawing marks on window decoration (true-false): ");
    scanf("%5s", temp_str);
    if (strcmp(temp_str, "true") == 0)
    {
        fptr = fopen("config", "a");
        fprintf(fptr,"show_marks yes\n");
        fclose(fptr);
    }
    else if (strcmp(temp_str, "false") == 0)
    {
        fptr = fopen("config", "a");
        fprintf(fptr,"show_marks no\n");
        fclose(fptr);
    }
    else
    {
        return 0;
    }

    printf("Tiling drag (off|modifier|titlebar): ");
    scanf("%8s", tiling_drag);
    fptr = fopen("config", "a");
    fprintf(fptr,"tiling_drag %s\n", tiling_drag);
    fclose(fptr);

    printf("Inner gap size for all windows (0 to disable ig): ");
    scanf("%d", &gaps_size);
    fptr = fopen("config", "a");
    fprintf(fptr,"gaps inner %d\n", gaps_size);
    fclose(fptr);

    printf("Outer gap type (outer|horizontal|vertical|top|left|bottom|right): ");
    scanf("%9s", gaps);
    printf("Outer gap size (0 to disable ig): ");
    scanf("%d", &gaps_outer);
    fptr = fopen("config", "a");
    fprintf(fptr,"gaps %s %d\n", gaps, gaps_outer);
    fclose(fptr);

    printf("Smart gaps (on|off|inverse_outer): ");
    scanf("%13s", smart_gaps);
    fptr = fopen("config", "a");
    fprintf(fptr,"smart_gaps %s\n", smart_gaps);
    fclose(fptr);

    printf("Enter border color for focused windows (hex code): #");
    scanf("%x", &border);
    printf("Enter background color for focused windows (hex code): #");
    scanf("%x", &bg);
    printf("Enter foreground color for focused windows (hex code): #");
    scanf("%x", &fg);
    printf("Enter indicator color for focused windows (hex code): #");
    scanf("%x", &indicator);
    printf("Enter child_border color for focused windows (the color around the child window is the child_border) (hex code): #");
    scanf("%x", &child_border);
    printf("For focused windows ↓\nBorder color: #%06x\nBackground color: #%06x\nForeground color: #%06x\nIndicator color: #%06x\nchild_border color: #%06x\n", border, bg, fg, indicator, child_border);
    printf("Are you sure? (true-false): ");
    scanf("%5s", &temp_str);

    if (strcmp (temp_str, "true") == 0)
    {
        printf("Enter border color for focused but inactive windows (hex code): #");
        scanf("%x", &border_in);
        printf("Enter background color for focused but inactive windows (hex code): #");
        scanf("%x", &bg_in);
        printf("Enter foreground color for focused but inactive windows (hex code): #");
        scanf("%x", &fg_in);
        printf("Enter indicator color for focused but inactive windows (hex code): #");
        scanf("%x", &indicator_in);
        printf("Enter child_border color for focused but inactive windows (the color around the child window is the child_border) (hex code): #");
        scanf("%x", &child_border_in);
        printf("For focused but inactive windows ↓\nBorder color: #%06x\nBackground color: #%06x\nForeground color: #%06x\nIndicator color: #%06x\nchild_border color: #%06x\n", border_in, bg_in, fg_in, indicator_in, child_border_in);
        printf("Are you sure? (true-false): ");
        scanf("%5s", &temp_str);

        if (strcmp (temp_str, "true") == 0)
        {
            printf("Enter border color for unfocused windows (hex code): #");
            scanf("%x", &border_un);
            printf("Enter background color for unfocused windows (hex code): #");
            scanf("%x", &bg_un);
            printf("Enter foreground color for unfocused windows (hex code): #");
            scanf("%x", &fg_un);
            printf("Enter indicator color for unfocused windows (hex code): #");
            scanf("%x", &indicator_un);
            printf("Enter child_border color for unfocused windows (the color around the child window is the child_border) (hex code): #");
            scanf("%x", &child_border_un);
            printf("For unfocused windows ↓\nBorder color: #%06x\nBackground color: #%06x\nForeground color: #%06x\nIndicator color: #%06x\nchild_border color: #%06x\n", border_un, bg_un, fg_un, indicator_un, child_border_un);
            printf("Are you sure? (true-false): ");
            scanf("%5s", &temp_str);

            if (strcmp (temp_str, "true") == 0)
            {
                printf("Enter border color for urgent windows (hex code): #");
                scanf("%x", &border_urg);
                printf("Enter background color for urgent windows (hex code): #");
                scanf("%x", &bg_urg);
                printf("Enter foreground color for urgent windows (hex code): #");
                scanf("%x", &fg_urg);
                printf("Enter indicator color for urgent windows (hex code): #");
                scanf("%x", &indicator_urg);
                printf("Enter child_border color for urgent windows (the color around the child window is the child_border) (hex code): #");
                scanf("%x", &child_border_urg);
                printf("For urgent windows ↓\nBorder color: #%06x\nBackground color: #%06x\nForeground color: #%06x\nIndicator color: #%06x\nchild_border color: #%06x\n", border_urg, bg_urg, fg_urg, indicator_urg, child_border_urg);
                printf("Are you sure? (true-false): ");
                scanf("%5s", &temp_str);

                if (strcmp (temp_str, "true") == 0)
                {
                    printf("Enter background color for placeholder windows (hex code): #");
                    scanf("%x", &bg_ph);
                    printf("Enter foreground color for placeholder windows (hex code): #");
                    scanf("%x", &fg_ph);
                     printf("Enter child_border color for placeholder windows (the color around the child window is the child_border) (hex code): #");
                    scanf("%x", &child_border_ph);
                    printf("For placeholder windows ↓\nBackground color: #%06x\nForeground color: #%06x\nchild_border color: #%06x\n", bg_ph, fg_ph, child_border_ph);
                    printf("Are you sure? (true-false): ");
                    scanf("%5s", &temp_str);

                    if (strcmp (temp_str, "true") == 0)
                    {
                        printf("(This is the background color which will be used to paint the background of the client window on top of which the client will be rendered.)\n(Only clients which do not cover the whole area of this window expose the color.)\nEnter background color (hex code): #");
                        scanf("%x", &background);
                        printf("Background color: #%06x\n", background);
                        printf("Are you sure? (true-false): ");
                        scanf("%5s", &temp_str);

                        if (strcmp (temp_str, "true") == 0)
                        {
                            FILE *fptr;
                            fptr = fopen("config", "a");
                            fprintf(fptr, "# class                 border  backgr. text    indicator child_border\nclient.focused          #%06x #%06x #%06x #%06x   #%06x\nclient.focused_inactive #%06x #%06x #%06x #%06x   #%06x\nclient.unfocused        #%06x #%06x #%06x #%06x   #%06x\nclient.urgent           #%06x #%06x #%06x #%06x   #%06x\nclient.placeholder      #000000 #%06x #%06x #000000   #%06x\nclient.background       #%06x\n", border, bg, fg, indicator, child_border, border_in, bg_in, fg_in, indicator_in, child_border_in, border_un, bg_un, fg_un, indicator_un, child_border_un, border_urg, bg_urg, fg_urg, indicator_urg, child_border_urg, bg_ph, fg_ph, child_border_ph, background);
                            fclose(fptr);
                            printf("Done, now copy the config file to ~/.config/i3/config\n");
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
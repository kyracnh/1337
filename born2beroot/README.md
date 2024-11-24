# crontab:
is a background process manager. The specified processes will be executed at the time you specify in the crontab file.

###     To properly configure crontab, we must edit the crontab file with the following command:

```
sudo crontab -u root -e
```

### In the file, we must add the following command for the script to execute every 10 minutes 

```
*/10 * * * * sh /path_to_file.sh
```

The syntax is as follows:

```
* * * * * command_to_execute
│ │ │ │ │
│ │ │ │ └─ Day of the week (0 - 6) (Sunday=0)
│ │ │ └─── Month (1 - 12)
│ │ └───── Day of the month (1 - 31)
│ └─────── Hour (0 - 23)
└───────── Minute (0 - 59)
```

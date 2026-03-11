# csvtoics

Converts work schedule CSV files into ICS calendar format for import into any calendar app.

## Usage

```bash
# Build
make

# Run
./csvtoics schedule.csv Max Mustermann Jan.25 Mar.25
```

## Arguments

| Argument | Description |
|----------|-------------|
| `.csv` | Input schedule file |
| `firstname` | Employee first name |
| `lastname` | Employee last name |
| `begin` | Start month (e.g. `01.25`, `Jan.25`, `Januar.25`) |
| `end` | End month |

## Output

Generates a standard `.ics` file that can be imported into Google Calendar, Apple Calendar, Outlook, etc.

## Tech

C++, no external dependencies.

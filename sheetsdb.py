import gspread
from oauth2client.service_account import ServiceAccountCredentials

def authenticate(secrets, sheet_name):
    scope = [
        "https://spreadsheets.google.com/feeds",
        "https://www.googleapis.com/auth/spreadsheets",
        "https://www.googleapis.com/auth/drive.file",
        "https://www.googleapis.com/auth/drive"
    ]
    creds = ServiceAccountCredentials.from_json_keyfile_name(secrets, scope)
    client = gspread.authorize(creds)
    sheet = client.open(sheet_name).sheet1
    return sheet


def read_messages(sheet):
    messages = sheet.get_all_records()
    return messages


def write_message(sheet, content, author, x, y):
    sheet.append_row([content, author, x, y])


if __name__ == "__main__":
    secrets = './credentials.json'
    sheet_name = 'gsheets-db'

    sheet = authenticate(secrets, sheet_name)

    write_message(sheet, "Hello, World!", "tavro", 0, 0)

    messages = read_messages(sheet)
    for message in messages:
        print(message)

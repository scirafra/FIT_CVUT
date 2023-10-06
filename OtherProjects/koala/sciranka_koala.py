import psycopg2
import json
import datetime
import decimal
from flask import Flask

# establishing the connection

url = "postgres://hvyvudcn:femV0c0uTBjqz2BGwFCH88vbJjatqCp5@dontpanic.k42.app/postgres"
conn = psycopg2.connect(url)

# Creating a cursor object using the cursor() method

cursor = conn.cursor()


def take_data(sql):
    cursor.execute(sql)
    result = cursor.fetchall()
    return result


def take_data_where(table, where):
    sql = """SELECT * from """ + table + """ where """ + where
    cursor.execute(sql)
    result = cursor.fetchall()
    return result


def make_dic(data, column_name):
    next_col = ""
    table_data = []
    column = take_data(
        """SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = \'"""
        + column_name
        + """\' ORDER BY ORDINAL_POSITION"""
    )

    for i in data:
        dic = {}

        for j in range(len(i)):

            if isinstance(i[j], decimal.Decimal):
                dic[column[j][0]] = float(i[j])

            elif isinstance(i[j], datetime.datetime):
                dic[column[j][0]] = str(i[j])

            else:
                dic[column[j][0]] = i[j]

        if column_name == "character":
            next_col = "nemesis"
            next_table = take_data_where(
                next_col, column_name + "_id=" + str(dic.get("id"))
            )
            dic[next_col] = make_dic(next_table, next_col)

        elif column_name == "nemesis":
            next_col = "secret"
            next_table = take_data_where(
                next_col, column_name + "_id=" + str(dic.get("id"))
            )
            dic[next_col] = make_dic(next_table, next_col)

        table_data.append(dic)

    return table_data


# Retrieving data

char_data = take_data("""SELECT * from character""")
char_count = take_data("""SELECT COUNT(id) AS a FROM character""")[0][0]
avg_char = round(take_data("""SELECT AVG(AGE(born)) FROM character""")[0][0].days / 365.25, 2)
avg_nem = round(float(take_data("""SELECT AVG(years) FROM nemesis """)[0][0]), 2)
avg_wei = round(float(take_data("""SELECT AVG(weight) FROM character""")[0][0]), 2)

# making json tree

my_dictionary = {}
my_dictionary["character_count"] = char_count
my_dictionary["character_average_age"] = avg_char
my_dictionary["character_average_weight"] = avg_wei
my_dictionary["nemesis_average_age"] = avg_nem
my_dictionary["character"] = make_dic(char_data, "character")

# api

app = Flask(__name__)


@app.route("/data/", methods=["GET"])
def data():
    return my_dictionary


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=105)

# Closing the connection

conn.close()

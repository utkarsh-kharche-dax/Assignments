# Generated by Django 3.2.14 on 2022-07-19 11:38

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('todotasks', '0001_initial'),
    ]

    operations = [
        migrations.AlterField(
            model_name='task',
            name='task_is_done',
            field=models.BooleanField(default=False),
        ),
    ]

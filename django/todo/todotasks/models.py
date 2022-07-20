from django.conf import settings
from django.db import models
from django.utils import timezone


class Task(models.Model):
    task_id = models.AutoField(primary_key=True)
    task_title = models.CharField(max_length=200)
    task_description = models.TextField()
    task_is_done = models.BooleanField(default=False)
    task_created_datetime = models.DateTimeField(default=timezone.now)
    task_updated_datetime = models.DateTimeField(blank=True, null=True)



    # def publish(self):
    #     self.published_date = timezone.now()
    #     self.save()

    def __str__(self):
        return self.task_title
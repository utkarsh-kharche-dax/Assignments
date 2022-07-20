from django import urls
from django.urls import path
from . import views

urlpatterns = [
    path('', views.task_list, name='task_list'),
    path('', views.viewAll, name='viewAll'),
    path('is_task_done/?P<int:id>/', views.is_task_done, name='is_task_done'),
    path('is_task_undone/?P<int:id>/', views.is_task_undone, name='is_task_undone'),
    # path('', views.update_task, name='update_task'),
    path('fetchRow/?P<int:id>/', views.fetchRow, name='fetchRow'),
    path('delete_task/?P<int:id>/', views.delete_task, name='delete_task'),

]
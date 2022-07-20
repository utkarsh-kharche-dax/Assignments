import {useState} from 'react';
import axios from 'axios';
const Forms = () => {
  const [formDataval, setFormData] = useState(
    {
      title:"",
      description:"",
      author:"",
      reading_time:""
    }
  );

  let baseURL="https://qghcujpqbvrdfszremfe.supabase.co/rest/v1/blogs"
  const handleClick = (e) => {
    e.preventDefault()
    axios.post(baseURL,formDataval ,{
      headers: {
          'Authorization': 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM',
          'apikey': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM'
      }
  }).then(
    console.log("Added")
  )
  };

  const inputHandler = (e) => {
    e.preventDefault()
    setFormData({
      ...formDataval,
      [e.target.name]:e.target.value
    });
  };
console.log(formDataval)
  return (
    <div className="container">
      <div className="card">
        <h5 className="card-header">Create a Blog</h5>
        <div className="card-body">
          <form>
            <div className="mb-3">
              <label for="title" className="form-label">Title</label>
              <input type="text" className="form-control" name='title'  onChange={inputHandler} placeholder="Enter Title" id="title" />
            </div>

            <div className="mb-3">
              <label for="description" className="form-label">Description</label>
              <textarea className="form-control" name='description' id="description" onChange={inputHandler} placeholder="Enter blog details" rows="3">
              </textarea>
            </div>
            <div className="mb-3">
              <label for="author" className="form-label">Author</label>
              <input type="text" className="form-control" name='author' onChange={inputHandler} placeholder="Enter author" id="author" />
            </div>
            <div className="mb-3">
              <label for="reading_time" className="form-label">Reading Time</label>
              <input type="text" className="form-control" name='reading_time'  onChange={inputHandler} placeholder="Enter Reading Time" id="reading_time" />
            </div>
            <button type="button" className="btn btn-info" onClick={handleClick}>Submit</button>
          </form>
        </div>
      </div>
    </div>

  )

}

export default Forms
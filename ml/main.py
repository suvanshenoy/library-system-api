# venv: site-packages


from flask import Flask, request, jsonify
from library.recommendation import RecommendationSystem

app = Flask(__name__)
rec_sys = RecommendationSystem()

@app.route('/recommendations', methods=['GET'])
def get_recommendations():
    user_id = int(request.args.get('userId'))
    recommendations = rec_sys.recommend(user_id)
    return jsonify(recommendations)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5001)

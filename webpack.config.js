const path = require("path");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const config = require("./config");

const outputDir = path.join(__dirname, "build/");

module.exports = {
  entry: "./src/Index.bs.js",
  output: {
    path: outputDir,
    publicPath: outputDir,
    filename: "Index.js"
  },
  plugins: [
    new HtmlWebpackPlugin({
      title: "test",
      template: "src/index.html",
      googleClientId: config.googleClientId
    })
  ]
};

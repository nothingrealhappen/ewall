const path = require("path");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const config = require("./config");

const outputDir = path.join(__dirname, "build/");

module.exports = {
  devtool: "eval-source-map",
  entry: "./src/Index.bs.js",
  output: {
    path: outputDir,
    filename: "Index.js"
  },
  plugins: [
    new HtmlWebpackPlugin({
      title: "Ewall - The wall for display cool & cooler & coolest event list",
      template: "src/index.html",
      googleClientId: config.googleClientId
    })
  ]
};
